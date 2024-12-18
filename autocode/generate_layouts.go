package autocode

import (
	"fmt"
	"sort"
	"strings"

	"github.com/Gophercraft/core/format/dbc"
	"github.com/Gophercraft/core/format/dbc/dbd"
	"github.com/Gophercraft/core/format/dbc/dbdefs"
)

type layoutTarget struct {
	Definition *dbd.Definition
	Layout     *dbd.Layout
}

func (g *Generator) findLayoutTargets() error {
	// fmt.Println(len(dbdefs.All))

	for _, def := range dbdefs.All {
		for l := range def.Layouts {
			layout := &def.Layouts[l]
			foundBuild := false
			for _, b := range layout.VerifiedBuilds {
				if b == g.Build {
					foundBuild = true
					break
				}
			}
			//
			if !foundBuild {
				for _, br := range layout.BuildRanges {
					if br.Contains(g.Build) {
						g.layouts = append(g.layouts, &layoutTarget{
							Definition: def,
							Layout:     layout,
						})
						foundBuild = true
						break
					}
				}
				if foundBuild {
					break
				}
			}

			if foundBuild {
				g.layouts = append(g.layouts, &layoutTarget{
					Definition: def,
					Layout:     layout,
				})
				break
			}
		}
	}

	sort.Slice(g.layouts, func(i, j int) bool {
		return g.layouts[i].Definition.Name <= g.layouts[j].Definition.Name
	})

	return nil
}

func (g *Generator) writeLayoutHeader(target *layoutTarget) (err error) {
	file, err := g.NewPrinter(fmt.Sprintf("src/db/rec/%sRec.hpp", target.Definition.Name))
	if err != nil {
		return err
	}

	importGuardToken := fmt.Sprintf("DB_REC_%s_REC_HPP", convertToScreamCase(target.Definition.Name))

	file.Printf("#ifndef %s\n", importGuardToken)
	file.Printf("#define %s\n", importGuardToken)
	file.Printf("\n")

	var (
		localimports  []string
		stdimports    []string
		decls         []string
		overrideLocal string
		overrideStd   string
		overrideDecl  string
	)

	overrideLocal, err = g.Cmd.Flags().GetString("layout-header-localimports")
	if err != nil {
		return
	}
	if overrideLocal != "" {
		localimports = strings.Split(overrideLocal, ",")
	}

	overrideStd, err = g.Cmd.Flags().GetString("layout-header-stdimports")
	if err != nil {
		return
	}
	if overrideStd != "" {
		stdimports = strings.Split(overrideStd, ",")
	}

	overrideDecl, err = g.Cmd.Flags().GetString("layout-header-decls")
	if err != nil {
		return
	}

	if overrideDecl != "" {
		decls = strings.Split(overrideDecl, ",")
	}

	indentImport := len(localimports) > 0 || len(stdimports) > 0 || len(decls) > 0

	for _, localimport := range localimports {
		file.Printf("#include \"%s\"\n", localimport)
	}

	for _, stdimport := range stdimports {
		file.Printf("#include <%s>\n", stdimport)
	}

	if indentImport {
		file.Printf("\n")
	}

	if len(decls) > 0 {
		for _, decl := range decls {
			file.Printf("%s;\n", decl)
		}

		file.Printf("\n")
	}

	indexIsID := target.Layout.Column("ID") == nil

	file.Printf("class %sRec {\n", target.Definition.Name)
	file.Printf("\tpublic:\n")

	normalizedColumnNames := make([]string, len(target.Layout.Columns))

	g.beginNormalization()
	for i := range target.Layout.Columns {
		normalizedColumnNames[i], err = g.normalizeFieldName(target.Layout.Columns[i].Name)
		if err != nil {
			return
		}
	}

	for i, column := range target.Layout.Columns {
		var (
			arraySuffix string
			cppType     string
			memberName  string
			columnDef   = target.Definition.Column(column.Name)
		)

		memberName = normalizedColumnNames[i]

		switch columnDef.Type {
		case dbd.LocString:
			cppType = "const char*"
		case dbd.String:
			cppType = "const char*"
		case dbd.Uint:
			cppType = fmt.Sprintf("uint%d_t", column.Bits)
		case dbd.Int:
			if column.Signed {
				cppType = fmt.Sprintf("int%d_t", column.Bits)
			} else {
				cppType = fmt.Sprintf("uint%d_t", column.Bits)
			}
		case dbd.Float:
			switch column.Bits {
			case 32:
				cppType = "float"
			case 64:
				cppType = "double"
			default:
				panic(column.Bits)
			}
		}

		if column.ArraySize > -1 {
			arraySuffix = fmt.Sprintf("[%d]", column.ArraySize) + arraySuffix
		}

		file.Printf("\t\t%s m_%s%s;", cppType, memberName, arraySuffix)

		if !columnDef.Verified {
			file.Printf(" // unconfirmed")
		}

		file.Printf("\n")
	}

	if indexIsID {
		file.Printf("\t\tint32_t m_generatedID;\n")
	}

	file.Printf("\n")
	file.Printf("\t\tstatic const char* GetFilename();\n")
	file.Printf("\t\tstatic uint32_t GetNumColumns();\n")
	file.Printf("\t\tstatic uint32_t GetRowSize();\n")
	file.Printf("\t\tstatic bool NeedIDAssigned();\n")
	file.Printf("\t\tint32_t GetID();\n")
	file.Printf("\t\tvoid SetID(int32_t id);\n")
	file.Printf("\t\tbool Read(SFile* f, const char* stringBuffer);\n")

	file.Printf("};\n")
	file.Printf("\n")
	file.Printf("#endif")

	return file.Close()
}

func (g *Generator) writeLayoutSource(target *layoutTarget) (err error) {
	var locSize int
	var rowSize int
	var numColumns int
	locSize, err = dbc.LocStringSize(g.Build)
	if err != nil {
		return
	}

	rowSize, numColumns, err = calcLayoutSize(g.Build, target)
	if err != nil {
		return
	}

	indexIsID := target.Layout.Column("ID") == nil

	file, err := g.NewPrinter(fmt.Sprintf("src/db/rec/%sRec.cpp", target.Definition.Name))
	if err != nil {
		return err
	}

	var (
		stdimports   []string
		localimports []string
		decls        []string
	)

	localimports = []string{
		fmt.Sprintf("db/rec/%sRec.hpp", target.Definition.Name),
	}

	var overrideLocal string
	overrideLocal, err = g.Cmd.Flags().GetString("layout-source-localimports")
	if err != nil {
		return
	}

	var overrideStd string
	overrideStd, err = g.Cmd.Flags().GetString("layout-source-stdimports")
	if err != nil {
		return
	}

	var overrideDecl string
	overrideDecl, err = g.Cmd.Flags().GetString("layout-source-decls")
	if err != nil {
		return
	}

	if overrideDecl != "" {
		decls = strings.Split(overrideDecl, ",")
	}

	if overrideLocal != "" {
		locals := strings.Split(overrideLocal, ",")
		localimports = append(localimports, locals...)
	}

	if overrideStd != "" {
		stds := strings.Split(overrideStd, ",")
		stdimports = append(stdimports, stds...)
	}

	indentImport := len(localimports) > 0 || len(stdimports) > 0 || len(decls) > 0

	for _, localimport := range localimports {
		file.Printf("#include \"%s\"\n", localimport)
	}

	for _, stdimport := range stdimports {
		file.Printf("#include <%s>\n", stdimport)
	}

	if indentImport {
		file.Printf("\n")
	}

	if len(decls) > 0 {
		for _, decl := range decls {
			file.Printf("%s;\n", decl)
		}

		file.Printf("\n")
	}

	file.Printf("const char* %sRec::GetFilename() {\n", target.Definition.Name)
	file.Printf("\treturn \"DBFilesClient\\\\%s.dbc\";\n", target.Definition.Name)
	file.Printf("}\n")
	file.Printf("\n")

	file.Printf("uint32_t %sRec::GetNumColumns() {\n", target.Definition.Name)
	file.Printf("\treturn %d;\n", numColumns)
	file.Printf("}\n")
	file.Printf("\n")

	file.Printf("uint32_t %sRec::GetRowSize() {\n", target.Definition.Name)
	file.Printf("\treturn %d;\n", rowSize)
	file.Printf("}\n")
	file.Printf("\n")

	file.Printf("bool %sRec::NeedIDAssigned() {\n", target.Definition.Name)
	file.Printf("\treturn %t;\n", indexIsID)
	file.Printf("}\n")
	file.Printf("\n")

	file.Printf("int32_t %sRec::GetID() {\n", target.Definition.Name)
	if indexIsID {
		file.Printf("\treturn this->m_generatedID;\n")
	} else {
		file.Printf("\treturn this->m_ID;\n")
	}
	file.Printf("}\n")
	file.Printf("\n")

	file.Printf("void %sRec::SetID(int32_t id) {\n", target.Definition.Name)
	if indexIsID {
		file.Printf("\tthis->m_generatedID = id;\n")
	} else {
		file.Printf("\tthis->m_ID = id;\n")
	}
	file.Printf("}\n")
	file.Printf("\n")

	file.Printf("bool %sRec::Read(SFile* f, const char* stringBuffer) {\n", target.Definition.Name)

	anyStrings := false

	normalizedColumnNames := make([]string, len(target.Layout.Columns))

	g.beginNormalization()
	for i := range target.Layout.Columns {
		normalizedColumnNames[i], err = g.normalizeFieldName(target.Layout.Columns[i].Name)
		if err != nil {
			return
		}
	}

	// Create string index arrays
	for i, columnLayout := range target.Layout.Columns {
		columnDef := target.Definition.Column(columnLayout.Name)

		memberName := normalizedColumnNames[i]

		switch columnDef.Type {
		case dbd.String:
			anyStrings = true
			isStringArray := columnLayout.ArraySize > -1
			if isStringArray {
				arrayCount := columnLayout.ArraySize

				file.Printf("\tuint32_t %sOfs[%d];\n", memberName, arrayCount)
			} else {
				file.Printf("\tuint32_t %sOfs;\n", memberName)
			}
		case dbd.LocString:
			anyStrings = true
			isLocArray := columnLayout.ArraySize > -1
			if isLocArray {
				arrayCount := columnLayout.ArraySize

				for e := 0; e < arrayCount; e++ {
					file.Printf("\tuint32_t %sOfs%d[%d];\n", memberName, e, locSize-1)
					file.Printf("\t\tuint32_t %sMask%d;\n", memberName, e)
				}
			} else {
				file.Printf("\tuint32_t %sOfs[%d];\n", memberName, locSize-1)
				file.Printf("\tuint32_t %sMask;\n", memberName)
			}
		}
	}

	if anyStrings {
		file.Printf("\n")
	}

	file.Printf("\tif (\n")

	sfileRead := func(x int, f string, args ...any) {
		file.Printf("\t\t")

		if x > 0 {
			file.Printf("|| ")
		}

		file.Printf(f, args...)

		file.Printf("\n")
	}

	// Read integer values & string indices
	for i, columnLayout := range target.Layout.Columns {
		memberName := normalizedColumnNames[i]

		columnDef := target.Definition.Column(columnLayout.Name)
		elementCount := columnLayout.ArraySize
		if elementCount == -1 {
			elementCount = 1
		}

		switch columnDef.Type {
		case dbd.String:
			isStringArray := columnLayout.ArraySize > -1
			if isStringArray {
				arrayCount := columnLayout.ArraySize

				for e := 0; e < arrayCount; e++ {
					sfileRead(i+e, "!SFile::Read(f, &%sOfs[%d], sizeof(uint32_t), nullptr, nullptr, nullptr)", memberName, e)
				}
			} else {
				sfileRead(i, "!SFile::Read(f, &%sOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)", memberName)
			}
		case dbd.LocString:
			isLocArray := columnLayout.ArraySize > -1
			if isLocArray {
				arrayCount := columnLayout.ArraySize

				for e := 0; e < arrayCount; e++ {
					for l := 0; l < locSize-1; l++ {
						sfileRead(i+e+l, "!SFile::Read(f, &%sOfs%d[%d], sizeof(uint32_t), nullptr, nullptr, nullptr)", memberName, e, l)
					}
					sfileRead(1, "!SFile::Read(f, &%sMask%d, sizeof(uint32_t), nullptr, nullptr, nullptr)", memberName, e)
				}
			} else {
				for l := 0; l < locSize-1; l++ {
					sfileRead(i+l, "!SFile::Read(f, &%sOfs[%d], sizeof(uint32_t), nullptr, nullptr, nullptr)", memberName, l)
				}
				sfileRead(1, "!SFile::Read(f, &%sMask, sizeof(uint32_t), nullptr, nullptr, nullptr)", memberName)
			}
		default:
			isArray := columnLayout.ArraySize > -1

			if isArray {
				arrayCount := columnLayout.ArraySize

				for e := 0; e < arrayCount; e++ {
					sfileRead(i+e, "!SFile::Read(f, &this->m_%s[%d], sizeof(m_%s[0]), nullptr, nullptr, nullptr)", memberName, e, memberName)
				}
			} else {
				sfileRead(i, "!SFile::Read(f, &this->m_%s, sizeof(this->m_%s), nullptr, nullptr, nullptr)", memberName, memberName)
			}
		}
	}

	file.Printf("\t) {\n")
	// file.Printf("\t\tConsoleWrite(\"Error reading %s\", WARNING_COLOR);\n", target.Definition.Name)
	file.Printf("\t\treturn false;\n")
	file.Printf("\t}\n")
	file.Printf("\n")

	currentLanguage, err := g.Cmd.Flags().GetString("locale-offset-token")
	if err != nil {
		return err
	}

	if anyStrings {
		file.Printf("\tif (stringBuffer) {\n")

		// Assign values from string buffer (if present)
		for i, columnLayout := range target.Layout.Columns {
			memberName := normalizedColumnNames[i]

			columnDef := target.Definition.Column(columnLayout.Name)

			switch columnDef.Type {
			case dbd.String:
				isStringArray := columnLayout.ArraySize > -1

				if isStringArray {
					for e := 0; e < columnLayout.ArraySize; e++ {
						file.Printf("\t\tthis->m_%s[%d] = &stringBuffer[%sOfs[%d]];\n", memberName, e, memberName, e)
					}
				} else {
					file.Printf("\t\tthis->m_%s = &stringBuffer[%sOfs];\n", memberName, memberName)
				}
			case dbd.LocString:
				isLocArray := columnLayout.ArraySize > -1

				if isLocArray {
					for e := 0; e < columnLayout.ArraySize; e++ {
						file.Printf("\t\tthis->m_%s[%d] = &stringBuffer[%sOfs%d[%s]];\n", memberName, e, memberName, e, currentLanguage)
					}
				} else {
					file.Printf("\t\tthis->m_%s = &stringBuffer[%sOfs[%s]];\n", memberName, memberName, currentLanguage)
				}
			}
		}

		file.Printf("\t} else {\n")

		// Assign empty string values if stringBuffer is not present.
		for i, columnLayout := range target.Layout.Columns {
			memberName := normalizedColumnNames[i]

			columnDef := target.Definition.Column(columnLayout.Name)

			switch columnDef.Type {
			case dbd.String:
				isStringArray := columnLayout.ArraySize > -1

				if isStringArray {
					for e := 0; e < columnLayout.ArraySize; e++ {
						file.Printf("\t\tthis->m_%s[%d] = \"\";\n", memberName, e)
					}
				} else {
					file.Printf("\t\tthis->m_%s = \"\";\n", memberName)
				}
			case dbd.LocString:
				isLocArray := columnLayout.ArraySize > -1

				if isLocArray {
					for e := 0; e < columnLayout.ArraySize; e++ {
						file.Printf("\t\tthis->m_%s[%d] = \"\";\n", memberName, e)
					}
				} else {
					file.Printf("\t\tthis->m_%s = \"\";\n", memberName)
				}
			}
		}

		file.Printf("\t}\n")
		file.Printf("\n")
	}
	file.Printf("\treturn true;\n")
	file.Printf("}\n")

	return file.Close()
}

func (g *Generator) writeLayouts() error {
	for _, layout := range g.layouts {
		if err := g.writeLayoutHeader(layout); err != nil {
			return err
		}

		if err := g.writeLayoutSource(layout); err != nil {
			return err
		}
	}
	return nil
}

func (g *Generator) generateLayouts() error {
	if err := g.findLayoutTargets(); err != nil {
		return err
	}

	if err := g.writeLayouts(); err != nil {
		return err
	}

	return nil
}
