package autocode

import (
	"os"
	"path/filepath"

	"github.com/Gophercraft/core/vsn"
)

type Generator struct {
	Build           vsn.Build
	OutputDirectory string
	DefsDirectory   string

	layouts []*layoutTarget
}

func NewGenerator(build vsn.Build) *Generator {
	g := new(Generator)
	g.Build = build
	return g
}

func (g *Generator) path(path string) string {
	return filepath.Join(g.OutputDirectory, path)
}

func (g *Generator) ensurePath(relpath string) error {
	path := g.path(relpath)

	dirContainingPath := filepath.Dir(path)

	if _, err := os.Stat(dirContainingPath); err != nil {
		return os.MkdirAll(dirContainingPath, 0700)
	}

	return nil
}

func (g *Generator) Generate() error {
	if err := g.loadAlternativeDefs(); err != nil {
		return err
	}

	if err := g.generateLayouts(); err != nil {
		return err
	}

	if err := g.generateLayoutReaders(); err != nil {
		return err
	}

	if err := g.generateStaticLoader(); err != nil {
		return err
	}

	return nil
}
