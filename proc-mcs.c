/*
 * SRR Process Multi-Category Security
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <string.h>

#include <srr/msg.h>
#include <srr/proc-mcs.h>

int proc_mcs_setcat (int proc, int pid, const int32_t *cat, size_t count)
{
	/* todo: use msg_send_mx to prevent extra copying */
	struct req {
		struct proc_mcs_setcat head;
		int32_t cat[count];
	} req;

	req.head.code  = PROC_MCS_SETCAT;
	req.head.pid   = pid;

	memcpy (req.cat, cat, sizeof (*cat) * count);

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_mcs_getcat (int proc, int pid, int32_t *cat, size_t count)
{
	struct proc_mcs_getcat req;

	req.code = PROC_MCS_GETCAT;
	req.pid  = pid;

	return msg_send (proc, &req, sizeof (req), cat, sizeof (*cat) * count);
}
