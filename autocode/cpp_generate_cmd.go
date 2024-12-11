package autocode

import (
	"log"

	"github.com/Gophercraft/core/version"
	"github.com/spf13/cobra"
)

var cpp_generate_cmd = &cobra.Command{
	Use:   "cpp",
	Short: "Run the C++ autocode generator",
	Long:  `Generate DBC code for Whoa.`,

	// Uncomment the following line if your bare application
	// has an action associated with it:
	Run: func(cmd *cobra.Command, args []string) {
		build, err := cmd.Flags().GetUint32("build")
		if err != nil {
			log.Fatal(err)
			return
		}
		loc, err := cmd.Flags().GetString("location")
		if err != nil {
			log.Fatal(err)
			return
		}
		defs, err := cmd.Flags().GetString("definitions")
		if err != nil {
			log.Fatal(err)
			return
		}
		cpp_generate(
			version.Build(build),
			loc,
			defs,
			cmd,
		)
	},
}

func init() {
	// Here you will define your flags and configuration settings.
	// Cobra supports persistent flags, which, if defined here,
	// will be global for your application.

	// rootCmd.PersistentFlags().StringVar(&cfgFile, "config", "", "config file (default is $HOME/.core.yaml)")

	// Cobra also supports local flags, which will only run
	// when this action is called directly.
	f := cpp_generate_cmd.Flags()
	f.StringP("location", "l", "", "The Whoa code directory")
	f.Uint32P("build", "b", 12340, "The dbc format build")
	f.BoolP("edit-warning", "e", true, "If true, show a DO NOT EDIT warning. This is to avoid robot code inadvertently replacing human code (which sucks!)")
	f.BoolP("normalize-members", "n", true, "If true, class members are automatically edited to be more aesthetically suitable to the Whoa project.")
	f.StringP("locale-offset-token", "i", "CURRENT_LANGUAGE", "Replaces the number (or macro of a number) of the localization offset to use.")
	f.StringP("static-db-load-all-name", "k", "StaticDb", "Changes the name of the files in src/db/ that contains all the DBs.")
	f.StringP("definitions", "d", "", "Optional: supply a definitions directory")
	f.StringP("layout-header-localimports", "p", "", "Optional: inside record layout headers, replace local #include directives with comma separated list e.g. whoa-autocode --layout-header-localimports \"util/SFile.hpp,client/Console.hpp\"")
	f.StringP("layout-header-stdimports", "q", "cstdint", "Optional: inside record layout headers, replace standard library #include directives with comma separated list e.g. whoa-autocode --layout-header-stdimports \"cstdint,storm/File.hpp\"")
	f.StringP("layout-source-localimports", "r", "util/SFile.hpp", "Sets local or quoted imports inside your source files")
	f.StringP("layout-source-stdimports", "s", "", "Sets std or bracketed imports inside your source files")
	f.StringP("layout-header-decls", "w", "class SFile", "Adds forward declarations to your header files")
	f.StringP("layout-source-decls", "x", "", "Adds forward declarations to your source files")
}

func cpp_generate(build version.Build, output, alternativeDefs string, cmd *cobra.Command) {
	g := NewGenerator(build)
	g.Cmd = cmd
	g.OutputDirectory = output
	g.DefsDirectory = alternativeDefs
	if err := g.GenerateCpp(); err != nil {
		log.Fatal(err)
	}
}
