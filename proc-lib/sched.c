/*
 * SRR Process Scheduler
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <srr/msg.h>
#include <marten/proc/sched.h>

int proc_sched_config (int proc, int pid, int policy, int prio)
{
	struct proc_sched_config req;

	req.code   = PROC_SCHED_CONFIG;
	req.pid    = pid;
	req.policy = policy;
	req.prio   = prio;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_sched_query (int proc, int pid, struct proc_sched_info *si)
{
	struct proc_sched_query req;

	req.code  = PROC_SCHED_QUERY;
	req.pid   = pid;

	return msg_send (proc, &req, sizeof (req), si, sizeof (*si));
}

int proc_sched_nice (int proc, int pid, int delta, int flags)
{
	struct proc_sched_nice req;

	req.code  = PROC_SCHED_NICE;
	req.pid   = pid;
	req.delta = delta;
	req.flags = flags;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_sched_start (int proc, int pid)
{
	struct proc_sched_start req;

	req.code = PROC_SCHED_START;
	req.pid  = pid;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_sched_stop (int proc, int pid)
{
	struct proc_sched_stop req;

	req.code = PROC_SCHED_STOP;
	req.pid  = pid;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_sched_yield (int target)
{
	struct proc_sched_yield req;

	req.code   = PROC_SCHED_YIELD;
	req.target = target;

	return msg_send (PROC_PID, &req, sizeof (req), NULL, 0);
}
