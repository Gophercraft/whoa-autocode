package autocode

import (
	"slices"
	"strings"
	"unicode"
)

func splitByCaseChange(tok string) (elements []string) {
	token := []rune(tok)

	var tmp string

	for i := 0; i < len(token)-1; i++ {
		first := token[i]
		second := token[i+1]

		tmp += string(unicode.ToLower(first))

		if unicode.IsUpper(second) && unicode.IsLower(first) || first >= '0' && first <= '9' {
			elements = append(elements, tmp)
			tmp = ""
		}
	}

	if tmp != "" {
		elements = append(elements, tmp)
	}

	if len(tok) >= 2 {
		beforeLast := token[len(token)-2]
		last := token[len(token)-1]

		if unicode.IsUpper(last) && unicode.IsLower(beforeLast) {

			elements = append(elements, string(unicode.ToLower(last)))

		} else {
			lastElement := elements[len(elements)-1]
			elements[len(elements)-1] = lastElement + string(unicode.ToLower(last))
		}
	}

	return
}

// Example: SomeInput_LikeThis -> SOME_INPUT_LIKE_THIS
func convertToScreamCase(definitionName string) string {
	var underscoreSplit []string

	underscoreSplit = strings.Split(definitionName, "_")

	var elements []string

	for _, underscoreElement := range underscoreSplit {
		caseSplit := splitByCaseChange(underscoreElement)
		for _, caseElement := range caseSplit {
			elements = append(elements, strings.ToUpper(caseElement))
		}
	}

	var trimElements []string
	for _, element := range elements {
		if element != "" {
			trimElements = append(trimElements, element)
		}
	}

	return strings.Join(elements, "_")
}

func shouldAlwaysUppercase(str string) bool {
	check := strings.ToUpper(str)

	alwaysUppercaseList := []string{
		"DB",
		"ID",
		"WMO",
	}

	for _, c := range alwaysUppercaseList {
		if c == check {
			return true
		}
	}

	return false
}

func (g *Generator) shouldNormalize() bool {
	nm, err := g.Cmd.Flags().GetBool("normalize-members")
	if err != nil {
		panic(err)
	}
	return nm
}

// Examples: SomeInput_LikeThis -> someInputLikeThis
//           ID -> ID
//           Thingamajig_ID -> thingamajigID

func (g *Generator) beginNormalization() {
	g.fieldNames = []string{}
}

func (g *Generator) normalizeFieldName(fieldName string) (s string, err error) {
	defer func() {
		if err == nil {
			g.fieldNames = append(g.fieldNames, s)
		}
	}()

	if !g.shouldNormalize() {
		s = fieldName
		return
	}

	if strings.HasPrefix(fieldName, "Field_") {
		s = "f" + fieldName[1:]
		return
	}

	langSuffix := false

	langEnd := strings.LastIndex(fieldName, "_lang")
	if langEnd > -1 {
		namePrefix := fieldName[:langEnd]
		// if slices.Contains(g.fieldNames, namePrefix) {
		// 	returnLang = true
		// 	fmt.Println("got lang string", fieldName)
		// }
		fieldName = namePrefix
		langSuffix = true
	}

	underscoreSplit := strings.Split(fieldName, "_")

	var elements []string

	for _, underscoreElement := range underscoreSplit {
		caseSplit := splitByCaseChange(underscoreElement)
		elements = append(elements, caseSplit...)
	}

	var trimElements []string
	for _, element := range elements {
		if element != "" {
			trimElements = append(trimElements, element)
		}
	}

	caseElements := make([]string, len(trimElements))

	for i := range caseElements {
		if i == 0 {
			if shouldAlwaysUppercase(trimElements[i]) {
				caseElements[i] = strings.ToUpper(trimElements[i])
			} else {
				caseElements[i] = strings.ToLower(trimElements[i])
			}
		} else {
			if shouldAlwaysUppercase(trimElements[i]) {
				caseElements[i] = strings.ToUpper(trimElements[i])
			} else {
				str := []rune(trimElements[i])
				str[0] = unicode.ToUpper(str[0])
				caseElements[i] = string(str)
			}
		}
	}

	s = strings.Join(caseElements, "")

	if slices.Contains(g.fieldNames, s) && langSuffix {
		s += "_lang"
	}

	return
}
