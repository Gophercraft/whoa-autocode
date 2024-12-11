package autocode

import "github.com/spf13/cobra"

var root_cmd = &cobra.Command{
	Use:   "whoa-autocode",
	Short: "Code generator",
	Long:  `Generates DBC client definitions for Whoa and Binana.`,
}

func init() {
	root_cmd.AddCommand(binana_generate_cmd)
	root_cmd.AddCommand(cpp_generate_cmd)
}
