/*
 * SRR Process Discretionary Access Control
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <string.h>

#include <srr/msg.h>
#include <srr/proc-dac.h>

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

int proc_dac_setgroups (int proc, int pid, const int32_t *gid, size_t count)
{
	/* todo: use msg_send_mx to prevent extra copying */
	struct req {
		struct proc_dac_setgroups head;
		int32_t gids[count];
	} req;

	req.head.code = PROC_DAC_SETGROUPS;
	req.head.pid  = pid;

	memcpy (req.gids, gid, sizeof (*gid) * count);

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_dac_getgroups (int proc, int pid, int32_t *gid, size_t count)
{
	struct proc_dac_getgroups req;

	req.code = PROC_DAC_GETGROUPS;
	req.pid  = pid;

	return msg_send (proc, &req, sizeof (req), gid, sizeof (*gid) * count);
}
