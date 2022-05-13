#!/usr/bin/python
"""
  (C) Copyright 2020-2022 Intel Corporation.

  SPDX-License-Identifier: BSD-2-Clause-Patent
"""
import socket

from apricot import TestWithServers
from ClusterShell.NodeSet import NodeSet

from network_utils import get_network_information, get_dmg_network_information, SUPPORTED_PROVIDERS


class DmgNetworkScanTest(TestWithServers):
    # pylint: disable=too-many-ancestors
    """Test Class Description:

    Simple test to verify the network scan function of the dmg tool.

    :avocado: recursive
    """

    def __init__(self, *args, **kwargs):
        """Initialize a DmgNetworkScanTest object."""
        super().__init__(*args, **kwargs)
        self.start_agents_once = False
        self.start_servers_once = False
        self.setup_start_agents = False
        self.setup_start_servers = False

    def setUp(self):
        """Set up each test case."""
        super().setUp()

        # Run the dmg command locally, unset config to run locally
        self.hostlist_servers = socket.gethostname().split(".")[0].split(",")
        self.access_points = self.hostlist_servers[:1]
        self.start_servers()
        self.dmg = self.get_dmg_command()

    def get_sys_info(self):
        """Get the system device information.

        Returns:
            list: list of NetworkDevice objects.

        """
        localhost = socket.gethostname().split(".")[0]
        server_provider = self.server_managers[0].get_config_value("provider")
        hosts = NodeSet(localhost)
        sys_info = []
        for entry in get_network_information(hosts, SUPPORTED_PROVIDERS):
            if entry.device.startswith("ib") and server_provider in entry.provider:
                sys_info.append(entry)
                sys_info[-1].ib_device = None
        return sys_info

    def get_dmg_info(self):
        """Get the information received from dmg network scan output.

        Returns:
            list: list of NetworkDevice objects.

        """
        return get_dmg_network_information(self.dmg.network_scan())

    def test_dmg_network_scan_basic(self):
        """JIRA ID: DAOS-2516

        Test Description: Test basic dmg functionality to scan the network
        devices on the system.

        :avocado: tags=all,daily_regression
        :avocado: tags=hw,small
        :avocado: tags=dmg,network_scan,basic
        """
        # Get info, both these functions will return a list of NetDev objects
        dmg_info = sorted(
            self.get_dmg_info(), key=lambda x: (x.device, x.provider))
        sys_info = sorted(
            self.get_sys_info(), key=lambda x: (x.device, x.provider))

        # Validate the output with what we expect.
        for title, info in {"SYS INFO": sys_info, "DMG INFO": dmg_info}.items():
            self.log.info("-" * 100)
            self.log.info(title)
            for entry in info:
                self.log.info("  %s", entry)
        self.log.info("-" * 100)
        msg = "\nDmg Info:\n{} \n\nSysInfo:\n{}".format(dmg_info, sys_info)
        self.assertEqual(sys_info, dmg_info, msg)
