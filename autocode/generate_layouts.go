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

func (g *Generator) isLayoutStatic(target *layoutTarget) bool {
	if target.Definition.Name == "Startup_Strings" {
		return false
	}

	return true
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

func (g *Generator) writeLayoutHeader(target *layoutTarget) error {
	file, err := g.NewPrinter(fmt.Sprintf("src/db/rec/%sRec.hpp", target.Definition.Name))
	if err != nil {
		return err
	}

	importGuardToken := fmt.Sprintf("DB_REC_%s_REC_HPP", convertToScreamCase(target.Definition.Name))

	file.Printf("#ifndef %s\n", importGuardToken)
	file.Printf("#define %s\n", importGuardToken)
	file.Printf("\n")

	var localimports = []string{
		"util/SFile.hpp",
	}

	var stdimports = []string{
		"cstdint",
	}

	overrideLocal, err := g.Cmd.Flags().GetString("layout-header-localimports")
	if err != nil {
		return err
	}
	if overrideLocal != "" {
		if overrideLocal == "nil" {
			localimports = nil
		} else {
			localimports = strings.Split(overrideLocal, ",")
		}
	}

	overrideStd, err := g.Cmd.Flags().GetString("layout-header-stdimports")
	if err != nil {
		return err
	}
	if overrideStd != "" {
		if overrideStd == "nil" {
			stdimports = nil
		} else {
			stdimports = strings.Split(overrideStd, ",")
		}
	}

	indentImport := len(localimports) > 0 || len(stdimports) > 0

	for _, localimport := range localimports {
		file.Printf("#include \"%s\"\n", localimport)
	}

	for _, stdimport := range stdimports {
		file.Printf("#include <%s>\n", stdimport)
	}

	if indentImport {
		file.Printf("\n")
	}

	// for _, layout := range g.layouts {
	// 	if err := g.writeLayout(file, layout); err != nil {
	// 		return err
	// 	}
	// }

	// file.Printf("\n")
	// file.Printf("#endif")

	// numColumns := 0
	// rowSize := 0
	indexIsID := target.Layout.Column("ID") == nil

	rowSize, numColumns, err := calcLayoutSize(g.Build, target)
	if err != nil {
		return err
	}
	// }

	// // Calculate number of columns and size of row

	// for _, column := range target.Layout.Columns {
	// 	columnDef := target.Definition.Column(column.Name)

	// 	numColumnElements := 1

	// 	if column.ArraySize > 0 {
	// 		numColumnElements = column.ArraySize
	// 	}

	// 	columnSize := 0

	// 	switch columnDef.Type {
	// 	case dbd.LocString:
	// 		columnSize = locSize * 4
	// 	case dbd.Int, dbd.Uint:
	// 		columnSize = (column.Bits / 8) * numColumnElements
	// 	case dbd.Float:
	// 		columnSize = (column.Bits / 8) * numColumnElements
	// 	case dbd.String:
	// 		columnSize = numColumnElements * 4
	// 	default:
	// 		panic("unknown type")
	// 	}

	// 	rowSize += columnSize

	// 	if columnDef.Type == dbd.LocString {
	// 		numColumns += locSize
	// 		continue
	// 	}

	// 	numColumns += numColumnElements
	// }

	// Begin writing record definition

	file.Printf("class %sRec {\n", target.Definition.Name)
	file.Printf("\tpublic:\n")

	file.Printf("\tstatic constexpr uint32_t columnCount = %d;\n", numColumns)
	file.Printf("\tstatic constexpr uint32_t rowSize = %d;\n", rowSize)
	file.Printf("\tstatic constexpr bool indexIsID = %t;\n", indexIsID)

	file.Printf("\n")

	for _, column := range target.Layout.Columns {
		var (
			arraySuffix string
			cppType     string
			memberName  string
			columnDef   = target.Definition.Column(column.Name)
		)

		memberName = column.Name

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

		file.Printf("\t%s m_%s%s;", cppType, memberName, arraySuffix)

		if !columnDef.Verified {
			file.Printf(" // unconfirmed")
		}

		file.Printf("\n")

		// if columnDef.Type == dbd.LocString {
		// 	file.Printf("\tuint32_t m_%s_bitmask;\n", memberName)
		// }
	}

	file.Printf("\n")
	file.Printf("\tstatic const char* GetFilename();\n")
	file.Printf("\tbool Read(SFile* f, const char* stringBuffer);\n")

	file.Printf("};\n")
	file.Printf("\n")
	file.Printf("#endif")

	return file.Close()
}

func (g *Generator) writeLayoutSource(target *layoutTarget) error {
	locSize, err := dbc.LocStringSize(g.Build)
	if err != nil {
		return err
	}

	file, err := g.NewPrinter(fmt.Sprintf("src/db/rec/%sRec.cpp", target.Definition.Name))
	if err != nil {
		return err
	}

	localimports := []string{
		fmt.Sprintf("db/rec/%sRec.hpp", target.Definition.Name),
	}

	for _, localimport := range localimports {
		file.Printf("#include \"%s\"\n", localimport)
	}

	if len(localimports) > 0 {
		file.Printf("\n")
	}

	file.Printf("const char* %sRec::GetFilename() {\n", target.Definition.Name)
	file.Printf("\treturn \"DBFilesClient\\\\%s.dbc\";\n", target.Definition.Name)
	file.Printf("}\n")
	file.Printf("\n")

	file.Printf("bool %sRec::Read(SFile* f, const char* stringBuffer) {\n", target.Definition.Name)

	anyStrings := false

	// Create string index arrays
	for _, columnLayout := range target.Layout.Columns {
		columnDef := target.Definition.Column(columnLayout.Name)

		switch columnDef.Type {
		case dbd.String:
			anyStrings = true
			isStringArray := columnLayout.ArraySize > -1
			if isStringArray {
				arrayCount := columnLayout.ArraySize

				file.Printf("\tuint32_t %sOfs[%d];\n", columnDef.Name, arrayCount)
			} else {
				file.Printf("\tuint32_t %sOfs;\n", columnDef.Name)
			}
		case dbd.LocString:
			anyStrings = true
			isLocArray := columnLayout.ArraySize > -1
			if isLocArray {
				arrayCount := columnLayout.ArraySize

				for e := 0; e < arrayCount; e++ {
					file.Printf("\tuint32_t %sOfs%d[%d];\n", columnDef.Name, e, locSize-1)
					file.Printf("\t\tuint32_t %sMask%d;\n", columnDef.Name, e)
				}
			} else {
				file.Printf("\tuint32_t %sOfs[%d];\n", columnDef.Name, locSize-1)
				file.Printf("\tuint32_t %sMask;\n", columnDef.Name)
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
					sfileRead(i+e, "!SFile::Read(f, &%sOfs[%d], sizeof(uint32_t), nullptr, nullptr, nullptr)", columnLayout.Name, e)
				}
			} else {
				sfileRead(i, "!SFile::Read(f, &%sOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)", columnLayout.Name)
			}
		case dbd.LocString:
			isLocArray := columnLayout.ArraySize > -1
			if isLocArray {
				arrayCount := columnLayout.ArraySize

				for e := 0; e < arrayCount; e++ {
					for l := 0; l < locSize-1; l++ {
						sfileRead(i+e+l, "!SFile::Read(f, &%sOfs%d[%d], sizeof(uint32_t), nullptr, nullptr, nullptr)", columnLayout.Name, e, l)
					}
					sfileRead(1, "!SFile::Read(f, &%sMask%d, sizeof(uint32_t), nullptr, nullptr, nullptr)", columnLayout.Name, e)
				}
			} else {
				for l := 0; l < locSize-1; l++ {
					sfileRead(i+l, "!SFile::Read(f, &%sOfs[%d], sizeof(uint32_t), nullptr, nullptr, nullptr)", columnLayout.Name, l)
				}
				sfileRead(1, "!SFile::Read(f, &%sMask, sizeof(uint32_t), nullptr, nullptr, nullptr)", columnLayout.Name)
			}
		default:
			isArray := columnLayout.ArraySize > -1

			if isArray {
				arrayCount := columnLayout.ArraySize

				for e := 0; e < arrayCount; e++ {
					sfileRead(i+e, "!SFile::Read(f, &this->m_%s[%d], sizeof(m_%s[0]), nullptr, nullptr, nullptr)", columnLayout.Name, e, columnLayout.Name)
				}
			} else {
				sfileRead(i, "!SFile::Read(f, &this->m_%s, sizeof(this->m_%s), nullptr, nullptr, nullptr)", columnLayout.Name, columnLayout.Name)
			}
		}
	}

	file.Printf("\t) {\n")
	// file.Printf("\t\tConsoleWrite(\"Error reading %s\", WARNING_COLOR);\n", target.Definition.Name)
	file.Printf("\t\treturn false;\n")
	file.Printf("\t}\n")
	file.Printf("\n")

	// optimization
	if !anyStrings {
		// file.Printf("\telse\n\t{\n\t\tresult = true;\n")
		goto done
	}

	file.Printf("\tif (stringBuffer) {\n")
	// file.Printf("\t\tresult = true;\n")

	// Assign values from string buffer (if present)
	for _, columnLayout := range target.Layout.Columns {
		columnDef := target.Definition.Column(columnLayout.Name)

		switch columnDef.Type {
		case dbd.String:
			isStringArray := columnLayout.ArraySize > -1

			if isStringArray {
				for e := 0; e < columnLayout.ArraySize; e++ {
					file.Printf("\t\tthis->m_%s[%d] = &stringBuffer[%sOfs[%d]];\n", columnLayout.Name, e, columnLayout.Name, e)
				}
			} else {
				file.Printf("\t\tthis->m_%s = &stringBuffer[%sOfs];\n", columnLayout.Name, columnLayout.Name)
			}
		case dbd.LocString:
			isLocArray := columnLayout.ArraySize > -1

			if isLocArray {
				for e := 0; e < columnLayout.ArraySize; e++ {
					file.Printf("\t\tthis->m_%s[%d] = &stringBuffer[%sOfs%d[CURRENT_LANGUAGE]];\n", columnLayout.Name, e, columnLayout.Name, e)
				}
			} else {
				file.Printf("\t\tthis->m_%s = &stringBuffer[%sOfs[CURRENT_LANGUAGE]];\n", columnLayout.Name, columnLayout.Name)
			}
		}
	}

	file.Printf("\t} else {\n")

	// \telse\n\t{\n")
	// file.Printf("\t\tresult = true;\n")

	// Assign empty string values if stringBuffer is not present.
	for _, columnLayout := range target.Layout.Columns {
		columnDef := target.Definition.Column(columnLayout.Name)

		switch columnDef.Type {
		case dbd.String:
			isStringArray := columnLayout.ArraySize > -1

			if isStringArray {
				for e := 0; e < columnLayout.ArraySize; e++ {
					file.Printf("\t\tthis->m_%s[%d] = \"\";\n", columnLayout.Name, e)
				}
			} else {
				file.Printf("\t\tthis->m_%s = \"\";\n", columnLayout.Name)
			}
		case dbd.LocString:
			isLocArray := columnLayout.ArraySize > -1

			if isLocArray {
				for e := 0; e < columnLayout.ArraySize; e++ {
					file.Printf("\t\tthis->m_%s[%d] = \"\";\n", columnLayout.Name, e)
				}
			} else {
				file.Printf("\t\tthis->m_%s = \"\";\n", columnLayout.Name)
			}
		}
	}

	file.Printf("\t}\n")
	file.Printf("\n")

done:
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
