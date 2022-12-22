/*
 * SRR Process Clocks
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <srr/msg.h>
#include <srr/proc-clock.h>

int proc_clock_gettime (int proc, int clock, struct proc_time *time)
{
	struct proc_clock_gettime req;

	req.code  = PROC_CLOCK_GETTIME;
	req.clock = clock;

	return msg_send (proc, &req, sizeof (req), time, sizeof (*time));
}

int proc_clock_settime (int proc, int clock, const struct proc_time *time)
{
	struct proc_clock_settime req;

	req.code  = PROC_CLOCK_SETTIME;
	req.clock = clock;
	req.time  = *time;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_clock_adjtime (int proc, int clock, int64_t delta, int rate,
			int64_t *left)
{
	const size_t alen = left == NULL ? 0 : sizeof (*left);
	struct proc_clock_adjtime req;

	req.code  = PROC_CLOCK_ADJTIME;
	req.clock = clock;
	req.delta = delta;
	req.rate  = rate;

	return msg_send (proc, &req, sizeof (req), left, alen);
}
