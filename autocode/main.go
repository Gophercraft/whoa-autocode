package autocode

import (
	"log"

	"github.com/Gophercraft/core/vsn"
	"github.com/spf13/cobra"
)

func runMain(build vsn.Build, output, alternativeDefs string, cmd *cobra.Command) {
	g := NewGenerator(build)
	g.Cmd = cmd
	g.OutputDirectory = output
	g.DefsDirectory = alternativeDefs
	if err := g.Generate(); err != nil {
		log.Fatal(err)
	}
}
