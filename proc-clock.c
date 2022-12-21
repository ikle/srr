/*
 * SRR Process Clocks
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <srr/msg.h>
#include <srr/proc-clock.h>

#include <srr/wire/proc-clock.h>

int proc_clock_gettime (int proc, int clock, struct timespec *ts)
{
	struct proc_clock_gettime req;
	struct proc_timespec ans;
	int ret;

	req.code  = PROC_CLOCK_GETTIME;
	req.clock = clock;

	ret = msg_send (PROC_PID, &req, sizeof (req), &ans, sizeof (ans));
	if (ret < 0)
		return ret;

	ts->tv_sec  = ans.sec;
	ts->tv_nsec = ans.nsec;
	return ret;
}

int proc_clock_settime (int proc, int clock, const struct timespec *ts)
{
	struct proc_clock_settime req;

	req.code    = PROC_CLOCK_SETTIME;
	req.clock   = clock;
	req.ts.sec  = ts->tv_sec;
	req.ts.nsec = ts->tv_nsec;

	return msg_send (PROC_PID, &req, sizeof (req), NULL, 0);
}

int proc_clock_adjtime (int proc, int clock, long delta, int rate, long *left)
{
	struct proc_clock_adjtime req;
	int64_t ans;
	int ret;

	req.code  = PROC_CLOCK_ADJTIME;
	req.clock = clock;
	req.delta = delta;
	req.rate  = rate;

	ret = msg_send (PROC_PID, &req, sizeof (req), &ans, sizeof (ans));
	if (ret < 0)
		return ret;

	if (left != NULL)
		*left = ans;

	return ret;
}
