/*
 * SRR Process Control
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <srr/msg.h>
#include <srr/proc-control.h>

int proc_control (int proc, const int32_t *req, int32_t *ans, size_t count)
{
	const size_t len = sizeof (req[0]) * 2 * count;

	proc = proc == 0 ? PROC_PID : proc;

	return msg_send (proc, req, len, ans, len);
}
