package autocode

import (
	"log"

	"github.com/Gophercraft/core/vsn"
	"github.com/spf13/cobra"
)

// rootCmd represents the base command when called without any subcommands
var rootCmd = &cobra.Command{
	Use:   "generate",
	Short: "Run the autocode generator",
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
		runMain(
			vsn.Build(build),
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
	rootCmd.Flags().StringP("location", "l", "", "The Whoa code directory")
	rootCmd.Flags().Uint32P("build", "b", 12340, "The dbc format build")
	rootCmd.Flags().BoolP("edit-warning", "e", true, "If true, show a DO NOT EDIT warning. This is to avoid robot code inadvertently replacing human code (which sucks!)")
	rootCmd.Flags().BoolP("normalize-members", "n", true, "If true, class members are automatically edited to be more aesthetically suitable to the Whoa project.")
	rootCmd.Flags().StringP("locale-offset-token", "i", "CURRENT_LANGUAGE", "Replaces the number (or macro of a number) of the localization offset to use.")
	rootCmd.Flags().StringP("static-db-load-all-name", "k", "StaticDb", "Changes the name of the files in src/db/ that contains all the DBs.")
	rootCmd.Flags().StringP("definitions", "d", "", "Optional: supply a definitions directory")
	rootCmd.Flags().StringP("layout-header-localimports", "p", "", "Optional: inside record layout headers, replace local #include directives with comma separated list e.g. whoa-autocode --layout-header-localimports \"util/SFile.hpp,client/Console.hpp\"")
	rootCmd.Flags().StringP("layout-header-stdimports", "q", "cstdint", "Optional: inside record layout headers, replace standard library #include directives with comma separated list e.g. whoa-autocode --layout-header-stdimports \"cstdint,storm/File.hpp\"")
	rootCmd.Flags().StringP("layout-source-localimports", "r", "util/SFile.hpp", "Sets local or quoted imports inside your source files")
	rootCmd.Flags().StringP("layout-source-stdimports", "s", "", "Sets std or bracketed imports inside your source files")
	rootCmd.Flags().StringP("layout-header-decls", "w", "class SFile", "Adds forward declarations to your header files")
	rootCmd.Flags().StringP("layout-source-decls", "x", "", "Adds forward declarations to your source files")
}

func Run() {
	rootCmd.Execute()
}
