package autocode

import (
	"fmt"

	"github.com/Gophercraft/core/format/dbc"
	"github.com/Gophercraft/core/format/dbc/dbd"
	"github.com/Gophercraft/core/version"
)

func calcLayoutSize(build version.Build, target *layoutTarget) (rowSize, numColumns int, err error) {
	var locSize int
	locSize, err = dbc.LocStringSize(build)
	if err != nil {
		return
	}

	for _, column := range target.Layout.Columns {
		columnDef := target.Definition.Column(column.Name)

		numColumnElements := 1

		if column.ArraySize > 0 {
			numColumnElements = column.ArraySize
		}

		columnSize := 0

		switch columnDef.Type {
		case dbd.LocString:
			columnSize = locSize * 4
		case dbd.Int, dbd.Uint:
			columnSize = (column.Bits / 8) * numColumnElements
		case dbd.Float:
			columnSize = (column.Bits / 8) * numColumnElements
		case dbd.String:
			columnSize = numColumnElements * 4
		default:
			err = fmt.Errorf("autocode: calcLayoutSize: unhandled dbc field: %s type: %d", columnDef.Name, columnDef.Type)
			return
		}

		rowSize += columnSize

		if columnDef.Type == dbd.LocString {
			numColumns += locSize
			continue
		}

		numColumns += numColumnElements
	}

	return
}
