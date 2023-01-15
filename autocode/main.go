package autocode

import (
	"log"

	"github.com/Gophercraft/core/vsn"
)

func runMain(build vsn.Build, output, alternativeDefs string) {
	g := NewGenerator(build)
	g.OutputDirectory = output
	g.DefsDirectory = alternativeDefs
	if err := g.Generate(); err != nil {
		log.Fatal(err)
	}
}
