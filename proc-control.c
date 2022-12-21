/*
 * SRR Process Control
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <srr/msg.h>
#include <srr/proc-control.h>

#include <srr/wire/proc.h>

int proc_control (int proc, const int32_t *req, int32_t *ans, size_t count)
{
	const size_t size = sizeof (req[0]) * 2 * count;

	return msg_send (PROC_PID, req, size, ans, size);
}
