/*
 * Marten Process Clocks: Wire Format
 *
 * Copyright (c) 2022-2023 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef MARTEN_PROC_WIRE_CLOCK_H
#define MARTEN_PROC_WIRE_CLOCK_H  1

#include <marten/proc/wire/core.h>

struct proc_time {
	int64_t sec;
	int64_t nsec;
};

struct proc_clock_gettime {
	int32_t code, clock;
};

struct proc_clock_settime {
	int32_t code, clock;
	struct proc_time time;
};

struct proc_clock_adjtime {
	int32_t code, clock;
	int64_t delta;
	int32_t rate, pad;
};

struct proc_clock_setres {
	int32_t code, clock, nsec, pad;
};

struct proc_clock_getres {
	int32_t code, clock;
};

#endif  /* MARTEN_PROC_WIRE_CLOCK_H */
