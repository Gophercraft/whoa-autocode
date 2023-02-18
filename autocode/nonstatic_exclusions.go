package autocode

var nonstaticExclusions = []string{
	"Startup_Strings",
}

func (g *Generator) isLayoutStatic(target *layoutTarget) bool {
	for _, excl := range nonstaticExclusions {
		if excl == target.Definition.Name {
			return false
		}
	}

	return true
}
