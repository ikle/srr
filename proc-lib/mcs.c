/*
 * Marten Process Multi-Category Security
 *
 * Copyright (c) 2022-2023 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <srr/msg.h>
#include <marten/proc/mcs.h>

int proc_mcs_setcats (int proc, int pid, int64_t active, int64_t family)
{
	struct proc_mcs_setcats req;

	req.code   = PROC_MCS_SETCATS;
	req.pid    = pid;
	req.active = active;
	req.family = family;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_mcs_getcats (int proc, int pid, struct proc_mcs_info *mi)
{
	struct proc_mcs_getcats req;

	req.code = PROC_MCS_GETCATS;
	req.pid  = pid;

	return msg_send (proc, &req, sizeof (req), mi, sizeof (*mi));
}
