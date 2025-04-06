package autocode

import (
	"bufio"
	"os"
)

func load_static_list(name string) (list []string, err error) {
	var (
		f *os.File
		s *bufio.Scanner
	)
	f, err = os.Open(name)
	if err != nil {
		return
	}
	s = bufio.NewScanner(f)
	for s.Scan() {
		list = append(list, s.Text())
	}
	if err = s.Err(); err != nil {
		return
	}
	return
}
