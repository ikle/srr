/*
 * SRR Process Scheduler: Wire Format
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_WIRE_PROC_SCHED_H
#define SRR_WIRE_PROC_SCHED_H  1

#include <srr/wire/proc.h>

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

struct proc_sched_yield {
	int32_t code, target;
};

#endif  /* SRR_WIRE_PROC_SCHED_H */
