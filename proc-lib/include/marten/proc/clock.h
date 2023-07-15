/*
 * Marten Process Clocks
 *
 * Copyright (c) 2022-2023 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef MARTEN_PROC_CLOCK_H
#define MARTEN_PROC_CLOCK_H  1

#include <marten/proc/wire/clock.h>

/*
 * The function proc_clock_gettime retrieve the time of the specified
 * clock.
 *
 * The function proc_clock_settime set the time of the specified clock.
 *
 * The function proc_clock_adjtime adjusts the specified clock by delta
 * nanoseconds if delta is not zero. The clock is partially adjusted
 * every system tick by (tick-size)/rate until it has been adjusted by
 * the entire delta amount. On success, returns the remaining delta.
 */
int  proc_clock_gettime (int proc, int clock, struct proc_time *time);
int  proc_clock_settime (int proc, int clock, const struct proc_time *time);
long proc_clock_adjtime (int proc, int clock, long delta, int rate);

/*
 * The function proc_clock_setres sets resolution for the specified clock.
 *
 * The function proc_clock_getres returns resolution of the specified clock.
 */
int proc_clock_setres (int proc, int clock, int32_t nsec);
int proc_clock_getres (int proc, int clock);

#endif  /* MARTEN_PROC_CLOCK_H */
