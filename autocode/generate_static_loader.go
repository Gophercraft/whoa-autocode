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

func (g *Generator) getStaticDbFilename() string {
	str, err := g.Cmd.Flags().GetString("static-db-load-all-name")
	if err != nil {
		panic(err)
	}
	return str
}

func (g *Generator) generateStaticDBHeader(list []string) error {
	file, err := g.NewPrinter(fmt.Sprintf("src/db/%s.hpp", g.getStaticDbFilename()))
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

	for _, item := range list {
		localimports = append(localimports, fmt.Sprintf("db/rec/%sRec.hpp", item))
	}

	for _, localimport := range localimports {
		file.Printf("#include \"%s\"\n", localimport)
	}

	file.Printf("\n")

	for _, target := range g.layouts {
		file.Printf("extern WowClientDB<%sRec> %s;\n", target, target)
	}

	file.Printf("\n")

	file.Printf("void StaticDBLoadAll(void (*loadFn)(WowClientDB_Base*, const char*, int32_t));\n")

	file.Printf("\n")

	file.Printf("#endif")

	return file.Close()
}

func (g *Generator) generateStaticDBLoader(list []string) error {
	file, err := g.NewPrinter(fmt.Sprintf("src/db/%s.cpp", g.getStaticDbFilename()))
	if err != nil {
		return err
	}

	localimports := []string{
		fmt.Sprintf("db/%s.hpp", g.getStaticDbFilename()),
	}

	for _, localimport := range localimports {
		file.Printf("#include \"%s\"\n", localimport)
	}

	file.Printf("\n")

	for _, target := range list {
		file.Printf("WowClientDB<%sRec> %s;\n", target, g.globalDBName(target))
	}

	file.Printf("\n")

	file.Printf("void StaticDBLoadAll(void (*loadFn)(WowClientDB_Base*, const char*, int32_t)) {\n")

	for _, target := range list {
		file.Printf("\tloadFn(&%s, __FILE__, __LINE__);\n", g.globalDBName(target))
	}

	file.Printf("}\n")
	file.Printf("\n")
	return nil
}

func (g *Generator) generateStaticLoader() error {
	list, err := load_static_list(fmt.Sprintf("static/%d.txt", g.Build))
	if err != nil {
		return err
	}

	if err := g.generateStaticDBHeader(list); err != nil {
		return err
	}

	if err := g.generateStaticDBLoader(list); err != nil {
		return err
	}

	return nil
}
