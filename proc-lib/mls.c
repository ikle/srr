/*
 * Marten Process Multi-Level Security
 *
 * Copyright (c) 2022-2023 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <srr/msg.h>
#include <marten/proc/mls.h>

int proc_mls_setlevel (int proc, int pid, int read, int write)
{
	struct proc_mls_setlevel req;

	req.code  = PROC_MLS_SETLEVEL;
	req.pid   = pid;
	req.read  = read;
	req.write = write;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_mls_getlevel (int proc, int pid, struct proc_mls_info *mi)
{
	struct proc_mls_getlevel req;

	req.code = PROC_MLS_GETLEVEL;
	req.pid  = pid;

	return msg_send (proc, &req, sizeof (req), mi, sizeof (*mi));
}
