/*
 * Marten Process Core
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <srr/msg.h>
#include <proc/process.h>

int proc_process_alloc (int proc, int flags)
{
	struct proc_process_alloc req;

	req.code  = PROC_PROCESS_ALLOC;
	req.flags = flags;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_process_free (int proc, int pid)
{
	struct proc_process_free req;

	req.code = PROC_PROCESS_FREE;
	req.pid  = pid;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}
