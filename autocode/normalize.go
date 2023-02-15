package autocode

import (
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

func normalizeFieldName(fieldName string) string {
	return fieldName
}
