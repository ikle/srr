/*
 * Marten Process Capabilities
 *
 * Copyright (c) 2022-2023 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <srr/msg.h>
#include <proc/caps.h>

int proc_caps_setmask (int proc, int pid, int active, int family)
{
	struct proc_caps_setmask req;

	req.code   = PROC_CAPS_SETMASK;
	req.pid    = pid;
	req.active = active;
	req.family = family;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_caps_query (int proc, int pid, struct proc_caps_info *ci)
{
	struct proc_caps_query req;

	req.code = PROC_CAPS_QUERY;
	req.pid  = pid;

	return msg_send (proc, &req, sizeof (req), ci, sizeof (*ci));
}
