/*
 * SRR Process Groupping
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_PROC_GROUP_H
#define SRR_PROC_GROUP_H  1

#include <srr/wire/proc-group.h>

/*
 * The function proc_group_steal changes the identifier of the specified
 * process, replacing the victim process with it.
 *
 * The function proc_group_adopt changes the parent of a process.
 *
 * The function proc_group_lead makes the specified process the leader
 * of its own process group.
 *
 * The function proc_group_chair makes the specified process the leader
 * of the new session and the leader of its own process group.
 *
 * The function proc_group_query queries information about the process
 * grouping.
 */
int proc_group_steal (int proc, int pid, int victim);
int proc_group_adopt (int proc, int pid, int parent);
int proc_group_lead  (int proc, int pid);
int proc_group_chair (int proc, int pid);
int proc_group_query (int proc, int pid, struct proc_group_info *gi);

#endif  /* SRR_PROC_GROUP_H */
