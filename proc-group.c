/*
 * SRR Process Groupping
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <srr/msg.h>
#include <srr/proc-group.h>

int proc_group_steal (int proc, int pid, int victim)
{
	struct proc_group_steal req;

	req.code   = PROC_GROUP_STEAL;
	req.pid    = pid;
	req.victim = victim;
	req.pad    = 0;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_group_adopt (int proc, int pid, int parent)
{
	struct proc_group_adopt req;

	req.code   = PROC_GROUP_ADOPT;
	req.pid    = pid;
	req.parent = parent;
	req.pad    = 0;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_group_lead (int proc, int pid)
{
	struct proc_group_lead req;

	req.code   = PROC_GROUP_LEAD;
	req.pid    = pid;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_group_chair (int proc, int pid)
{
	struct proc_group_chair req;

	req.code   = PROC_GROUP_CHAIR;
	req.pid    = pid;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_group_query (int proc, int pid, struct proc_group_info *gi)
{
	struct proc_group_query req;

	req.code = PROC_GROUP_QUERY;
	req.pid  = pid;

	return msg_send (proc, &req, sizeof (req), gi, sizeof (*gi));
}
