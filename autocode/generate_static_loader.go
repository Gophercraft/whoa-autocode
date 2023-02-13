package autocode

import (
	"fmt"
	"unicode"
)

func (g *Generator) globalDBName(name string) string {
	gname := []rune("g_" + name + "DB")
	gname[2] = unicode.ToLower(gname[2])
	return string(gname)
}

func (g *Generator) generateStaticDBHeader() error {
	file, err := g.NewPrinter("src/db/StaticDB.hpp")
	if err != nil {
		return err
	}

	file.Printf("#ifndef DB_STATIC_DB_HPP\n")
	file.Printf("#define DB_STATIC_DB_HPP\n")
	file.Printf("\n")

	localimports := []string{
		"db/WowClientDB_Base.hpp",
		"db/WowClientDB.hpp",
	}

	for _, item := range g.layouts {
		if g.isLayoutStatic(item) {
			localimports = append(localimports, fmt.Sprintf("db/rec/%sRec.hpp", item.Definition.Name))
		}
	}

	for _, localimport := range localimports {
		file.Printf("#include \"%s\"\n", localimport)
	}

	file.Printf("\n")

	for _, target := range g.layouts {
		file.Printf("extern WowClientDB<%sRec> %s;\n", target.Definition.Name, g.globalDBName(target.Definition.Name))
	}

	file.Printf("\n")

	file.Printf("void StaticDBLoadAll(void (*loadFn)(WowClientDB_Base*, const char*, int32_t));\n")

	file.Printf("\n")

	file.Printf("#endif")

	return file.Close()
}

func (g *Generator) generateStaticDBLoader() error {
	file, err := g.NewPrinter("src/db/StaticDB.cpp")
	if err != nil {
		return err
	}

	localimports := []string{
		"db/StaticDB.hpp",
	}

	for _, localimport := range localimports {
		file.Printf("#include \"%s\"\n", localimport)
	}

	file.Printf("\n")

	for _, target := range g.layouts {
		file.Printf("WowClientDB<%sRec> %s;\n", target.Definition.Name, g.globalDBName(target.Definition.Name))
	}

	file.Printf("\n")

	file.Printf("void StaticDBLoadAll(void (*loadFn)(WowClientDB_Base*, const char*, int32_t)) {\n")

	for _, target := range g.layouts {
		if g.isLayoutStatic(target) {
			file.Printf("\tloadFn(&%s, __FILE__, __LINE__);\n", g.globalDBName(target.Definition.Name))
		}
	}

	file.Printf("}\n")
	file.Printf("\n")
	return nil
}

func (g *Generator) generateStaticLoader() error {
	if err := g.generateStaticDBHeader(); err != nil {
		return err
	}

	if err := g.generateStaticDBLoader(); err != nil {
		return err
	}

	return nil
}
