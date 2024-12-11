package autocode

import (
	"os"
	"path/filepath"

	"github.com/Gophercraft/core/version"
	"github.com/spf13/cobra"
)

type Generator struct {
	Build           version.Build
	OutputDirectory string
	DefsDirectory   string
	Cmd             *cobra.Command

	layouts []*layoutTarget
}

func NewGenerator(build version.Build) *Generator {
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
