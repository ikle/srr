/*
 * Marten Process Discretionary Access Control
 *
 * Copyright (c) 2022-2023 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <string.h>

#include <srr/msg.h>
#include <proc/dac.h>

int proc_dac_setids (int proc, int pid, int uid, int gid)
{
	struct proc_dac_setids req;

	req.code = PROC_DAC_SETIDS;
	req.pid  = pid;
	req.uid  = uid;
	req.gid  = gid;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_dac_setmask (int proc, int pid, int active, int family)
{
	struct proc_dac_setmask req;

	req.code   = PROC_DAC_SETMASK;
	req.pid    = pid;
	req.active = active;
	req.family = family;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_dac_query (int proc, int pid, struct proc_dac_info *di)
{
	struct proc_dac_query req;

	req.code = PROC_DAC_QUERY;
	req.pid  = pid;

	return msg_send (proc, &req, sizeof (req), di, sizeof (*di));
}
