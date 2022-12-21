/*
 * SRR Process Clocks
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_PROC_CLOCK_H
#define SRR_PROC_CLOCK_H  1

#include <time.h>

/*
 * The function proc_clock_gettime retrieve the time of the specified
 * clock.
 *
 * The function proc_clock_settime set the time of the specified clock.
 *
 * The function proc_clock_adjtime adjusts the specified clock by delta
 * nanoseconds if delta is not zero. The clock is partially adjusted
 * every system tick by (tick-size)/rate until it has been adjusted by
 * the entire delta amount. If the left is not NULL, then the remaining
 * delta is stored in it.
 */
int proc_clock_gettime (int proc, int clock, struct timespec *ts);
int proc_clock_settime (int proc, int clock, const struct timespec *ts);
int proc_clock_adjtime (int proc, int clock, long delta, int rate, long *left);

#endif  /* SRR_PROC_CLOCK_H */
