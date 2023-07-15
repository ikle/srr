/*
 * Marten Process Scheduler: Wire Format
 *
 * Copyright (c) 2022-2023 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef MARTEN_PROC_WIRE_SCHED_H
#define MARTEN_PROC_WIRE_SCHED_H  1

#include <marten/proc/wire/core.h>

struct proc_sched_config {
	int32_t code, pid, policy, prio;
};

struct proc_sched_info {
	int32_t policy, prio;
};

struct proc_sched_query {
	int32_t code, pid;
};

struct proc_sched_nice {
	int32_t code, pid, delta, flags;
};

struct proc_sched_start {
	int32_t code, pid;
};

struct proc_sched_stop {
	int32_t code, pid;
};

struct proc_sched_yield {
	int32_t code, target;
};

#endif  /* MARTEN_PROC_WIRE_SCHED_H */
