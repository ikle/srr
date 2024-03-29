/*
 * Marten Process Clocks
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <srr/msg.h>
#include <marten/proc/clock.h>

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

long proc_clock_adjtime (int proc, int clock, long delta, int rate)
{
	struct proc_clock_adjtime req;

	req.code  = PROC_CLOCK_ADJTIME;
	req.clock = clock;
	req.delta = delta;
	req.rate  = rate;
	req.pad   = 0;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_clock_setres (int proc, int clock, int32_t nsec)
{
	struct proc_clock_setres req;

	req.code  = PROC_CLOCK_SETRES;
	req.clock = clock;
	req.nsec  = nsec;
	req.pad   = 0;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_clock_getres (int proc, int clock)
{
	struct proc_clock_getres req;

	req.code  = PROC_CLOCK_GETRES;
	req.clock = clock;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}
