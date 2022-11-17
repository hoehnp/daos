//
// (C) Copyright 2019-2022 Intel Corporation.
//
// SPDX-License-Identifier: BSD-2-Clause-Patent
//

package main

import (
	"fmt"

	"github.com/daos-stack/daos/src/control/common/cmdutil"
	"github.com/daos-stack/daos/src/control/lib/support"
)

type SupportCmd struct {
	CollectLog collectLogCmd `command:"collectlog" description:"Collect logs from server"`
}

// collectLogCmd is the struct representing the command to scan the machine for network interface devices
// that match the given fabric provider.
type collectLogCmd struct {
	optCfgCmd
	cmdutil.LogCmd
	TargetFolder string `short:"s" long:"loglocation" description:"Folder location where log is going to be copied"`
	Archive bool `short:"z" long:"archive" description:"Archive the log/config files"`
}

func (cmd *collectLogCmd) Execute(_ []string) error {
	if cmd.TargetFolder == "" {
		cmd.TargetFolder = "/tmp/daos_support_logs"
	}

	fmt.Println(" -- SAMIR Server Config cmd.config -- ", cmd.configPath())

	err := support.CollectServerLog(cmd.TargetFolder, cmd.configPath())
	if err != nil {
		return err
	}

	if cmd.Archive == true {
		err = support.ArchiveLogs(cmd.TargetFolder)
		if err != nil {
			return err
		}
	}

	return nil
}
