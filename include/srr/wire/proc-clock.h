/*
 * SRR Process Clocks: Wire Format
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_WIRE_PROC_CLOCK_H
#define SRR_EIRE_PROC_CLOCK_H  1

#include <srr/wire/proc.h>

struct proc_timespec {
	int64_t sec;
	int64_t nsec;
};

struct proc_clock_gettime {
	int32_t code, clock;
};

struct proc_clock_settime {
	int32_t code, clock;
	struct proc_timespec ts;
};

struct proc_clock_adjtime {
	int32_t code, clock;
	int64_t delta;
	int32_t rate, pad;
};

#endif  /* SRR_WIRE_PROC_CLOCK_H */
