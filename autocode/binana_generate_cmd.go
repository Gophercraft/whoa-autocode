package autocode

import (
	"log"

	"github.com/Gophercraft/core/version"
	"github.com/spf13/cobra"
)

var binana_generate_cmd = &cobra.Command{
	Use:   "binana",
	Short: "generate Binana code",
	Long:  `Generate an extremely long C header that defines all records`,

	// Uncomment the following line if your bare application
	// has an action associated with it:
	Run: func(cmd *cobra.Command, args []string) {
		build, err := cmd.Flags().GetUint32("build")
		if err != nil {
			log.Fatal(err)
			return
		}
		location, err := cmd.Flags().GetString("location")
		if err != nil {
			log.Fatal(err)
			return
		}
		defs, err := cmd.Flags().GetString("definitions")
		if err != nil {
			log.Fatal(err)
			return
		}
		binana_generate(
			version.Build(build),
			location,
			defs,
			cmd,
		)
	},
}

func init() {
	f := binana_generate_cmd.Flags()
	f.StringP("location", "l", "binana_records.h", "The Binana header file")
	f.Uint32P("build", "b", 12340, "The dbc format build")
	f.BoolP("edit-warning", "e", true, "If true, show a DO NOT EDIT warning. This is to avoid robot code inadvertently replacing human code (which sucks!)")
	f.BoolP("normalize-members", "n", true, "If true, class members are automatically edited to be more aesthetically suitable to the Whoa project.")
	f.StringP("definitions", "d", "", "Optional: supply a definitions directory")
}

func binana_generate(build version.Build, location, definitions string, cmd *cobra.Command) {
	g := NewGenerator(build)
	g.Cmd = cmd
	g.DefsDirectory = definitions
	if err := g.GenerateBinana(location); err != nil {
		log.Fatal(err)
	}
	return

}
