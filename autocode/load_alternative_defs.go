package autocode

import (
	"os"
	"path/filepath"
	"strings"

	"github.com/Gophercraft/core/format/dbc/dbd"
	"github.com/Gophercraft/core/format/dbc/dbdefs"
	"github.com/Gophercraft/log"
)

func (g *Generator) loadDefinition(path string) error {
	log.Println("Loading definition", path)

	definitionName := strings.TrimSuffix(
		filepath.Base(path),
		".dbd")

	file, err := os.OpenFile(path, os.O_RDONLY, 0700)
	if err != nil {
		return err
	}

	def, err := dbd.DecodeDefinition(definitionName, file)
	if err != nil {
		return err
	}

	_, overwrite := dbdefs.All[definitionName]
	if overwrite {
		log.Println("Overwriting definition named", definitionName)
	}

	dbdefs.All[definitionName] = def

	return file.Close()
}

func (g *Generator) loadAlternativeDefs() error {
	// No problem
	if g.DefsDirectory == "" {
		return nil
	}

	list, err := os.ReadDir(g.DefsDirectory)
	if err != nil {
		return err
	}

	for _, ent := range list {
		if !ent.IsDir() && strings.HasSuffix(ent.Name(), ".dbd") {
			if err := g.loadDefinition(filepath.Join(g.DefsDirectory, ent.Name())); err != nil {
				return err
			}
		}
	}

	return nil
}
