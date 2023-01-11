/*
 * Marten Process Scheduler
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef PROC_SCHED_H
#define PROC_SCHED_H  1

#include <proc/wire/sched.h>

/*
 * The function proc_sched_config changes the process scheduling algorithm
 * and/or its priority. For positive policy, if successful, returns the
 * previous value of the policy. For a negative policy, it only changes
 * the priority and, if successful, returns the previous priority value.
 *
 * The function proc_sched_query queries the process scheduling algorithm
 * and its priority. Returns 0 on success.
 *
 * The function proc_sched_nice changes the process priority by adding
 * delta to it. If successful, returns the new priority value.
 *
 * The function proc_sched_yield causes the calling process to yield
 * execution to another process. If target is positive and the specified
 * process is not blocked, then execution yields to it. Otherwise,
 * execution is passed to the next process in the execution queue.
 */
int proc_sched_config (int proc, int pid, int policy, int prio);
int proc_sched_query  (int proc, int pid, struct proc_sched_info *si);
int proc_sched_nice   (int proc, int pid, int delta,  int flags);
int proc_sched_yield  (int target);

#endif  /* PROC_SCHED_H */
