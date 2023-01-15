package autocode

import (
	"encoding/binary"
	"fmt"
	"os"
	"path/filepath"
	"strings"
	"testing"

	"github.com/Gophercraft/core/format/dbc"
	"github.com/Gophercraft/core/format/dbc/dbdefs"
	"github.com/Gophercraft/core/vsn"
)

func testBuildLayoutSize(build vsn.Build, dbcName, dbcPath string, t *testing.T) {
	dbdef, err := dbdefs.Lookup(dbcName)
	if err != nil {
		t.Fatal(err)
	}

	var (
		target = &layoutTarget{
			Definition: dbdef,
		}
	)

	for i := range dbdef.Layouts {
		pLayout := &dbdef.Layouts[i]

		foundBuild := false

		for _, verifiedBuild := range pLayout.VerifiedBuilds {
			if verifiedBuild == build {
				foundBuild = true
				target.Layout = pLayout
				break
			}
		}

		if foundBuild {
			break
		}

		for _, buildRange := range pLayout.BuildRanges {
			if buildRange.Contains(build) {
				foundBuild = true
				target.Layout = pLayout
				break
			}
		}

		if foundBuild {
			break
		}
	}

	if target.Layout == nil {
		t.Fatal("could not find valid layout for", dbcName, "version", build)
	}

	dbcFile, err := os.OpenFile(dbcPath, os.O_RDONLY, 0700)
	if err != nil {
		t.Fatal(err)
	}

	var magic [4]byte
	if _, err := dbcFile.Read(magic[:]); err != nil {
		// t.Fatal("Error reading dbc file magic", dbcPath, err)
		return
	}

	var header dbc.WDBCHeader
	if err := binary.Read(dbcFile, binary.LittleEndian, &header); err != nil {
		t.Fatal(string(magic[:]), err)
	}

	dbcFile.Close()

	rowSize, numColumns, err := calcLayoutSize(build, target)
	if err != nil {
		t.Fatal(err)
	}

	fmt.Println(dbcPath, rowSize, numColumns)

	if rowSize != int(header.RecordSize) {
		t.Fatal("MISMATCH!", "Row size in file", dbcPath, "is", header.RecordSize, ", but whoa-autocode calculated it as being", rowSize)
	}

	if numColumns != int(header.FieldCount) {
		t.Fatal("MISMATCH!", "Number of columns in file", dbcPath, "is", header.FieldCount, ", but whoa-autocode calculated it as being", numColumns)
	}
}

func testBuildLayoutSizes(build vsn.Build, t *testing.T) {
	wd, err := os.Getwd()
	if err != nil {
		t.Fatal(err)
	}
	base := filepath.Join(wd, "testfiles", fmt.Sprintf("%d", build))

	dbcList, err := os.ReadDir(base)
	if err != nil {
		t.Fatal(err)
	}

	for _, dbc := range dbcList {
		fullpath := filepath.Join(base, dbc.Name())
		dbcName := strings.TrimSuffix(dbc.Name(), ".dbc")

		testBuildLayoutSize(build, dbcName, fullpath, t)
	}
}

func TestLayoutSize(t *testing.T) {
	wd, _ := os.Getwd()
	fmt.Println(wd)

	for _, testbuild := range []vsn.Build{
		vsn.V3_3_5a,
	} {
		testBuildLayoutSizes(testbuild, t)
	}
}
