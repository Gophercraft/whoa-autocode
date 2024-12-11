package autocode

func (g *Generator) GenerateCpp() error {
	if err := g.loadAlternativeDefs(); err != nil {
		return err
	}

	if err := g.generateLayouts(); err != nil {
		return err
	}

	// if err := g.generateLayoutReaders(); err != nil {
	// 	return err
	// }

	if err := g.generateStaticLoader(); err != nil {
		return err
	}

	return nil
}
