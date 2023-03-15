//
// (C) Copyright 2022-2023 Intel Corporation.
//
// SPDX-License-Identifier: BSD-2-Clause-Patent
//

package main

import (
	"fmt"
	"os"

	"github.com/daos-stack/daos/src/control/common/cmdutil"
	"github.com/daos-stack/daos/src/control/lib/support"
)

type SupportCmd struct {
	CollectLog collectLogCmd `command:"collect-log" description:"Collect logs from client"`
}

// collectLogCmd is the struct representing the command to collect the log from client side.
type collectLogCmd struct {
	configCmd
	cmdutil.LogCmd
	ConfigPath string `short:"o" long:"config-path" required:"1" description:"Path to agent configuration file"`
	support.CollectLogSubCmd
}

func (cmd *collectLogCmd) Execute(_ []string) error {
	var LogCollection = map[int32][]string{
		support.CopyAgentConfigEnum:  {""},
		support.CollectAgentLogEnum:  {""},
		support.CollectAgentCmdEnum:  support.AgentCmd,
		support.CollectClientLogEnum: {""},
		support.CollectSystemCmdEnum: support.SystemCmd,
	}

	// Default 3 steps of log/conf collection.
	progress := support.ProgressBar{
		Total:     len(LogCollection),
		NoDisplay: false,
	}

	if cmd.Archive {
		progress.Total++
	}

	// Copy the custom log location
	if cmd.ExtraLogsDir != "" {
		LogCollection[support.CollectExtraLogsDirEnum] = []string{""}
		progress.Total++
	}

	if cmd.TargetFolder == "" {
		cmd.TargetFolder = "/tmp/daos_support_client_logs"
	}
	cmd.Infof("Support Logs will be copied to %s", cmd.TargetFolder)

	progress.Steps = 100 / progress.Total
	params := support.CollectLogsParams{}
	params.TargetFolder = cmd.TargetFolder
	params.ExtraLogsDir = cmd.ExtraLogsDir
	params.Config = cmd.ConfigPath
	for logFunc, logCmdSet := range LogCollection {
		for _, logCmd := range logCmdSet {
			cmd.Debugf("Log Function Enum = %d -- Log Collect Cmd = %s ", logFunc, logCmd)
			params.LogFunction = logFunc
			params.LogCmd = logCmd

			err := support.CollectSupportLog(cmd.Logger, params)
			if err != nil {
				fmt.Println(err)
				if cmd.Stop {
					return err
				}
			}
		}
		fmt.Printf(progress.Display())
	}

	if cmd.Archive {
		cmd.Debugf("Archiving the Log Folder %s", cmd.TargetFolder)
		err := support.ArchiveLogs(cmd.Logger, params)
		if err != nil {
			return err
		}

		for i := 1; i < 3; i++ {
			os.RemoveAll(cmd.TargetFolder)
		}
	}

	fmt.Printf(progress.Display())

	return nil
}
