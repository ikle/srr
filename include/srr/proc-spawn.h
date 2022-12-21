/*
 * SRR Process Spawn
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_PROC_SPAWN_H
#define SRR_PROC_SPAWN_H  1

#include <srr/proc-control.h>

/*
 * The function proc_spawn creates a new or replaces the current process
 * with an image from resource (nid, pid, handle), passing it arguments
 * via argv, environment variables via envp, and executing a sequence of
 * process control commands from ops.
 *
 * If nid is zero, then the image is on the local node. If pid is zero,
 * then the image is copied from the image of the current process (fork).
 * More specifically, if pid is zero, then the source of the resource is
 * (caller-nid, proc-pid, caller-real-pid): this replacement is done
 * inside the proc_spawn before the request is passed to proc.
 *
 * To replace the current process with the newly created one (exec), the
 * command sequence ops must contain a command to change the PID of the
 * process to the PID of the calling process.
 */
int proc_spawn (int proc, int nid, int pid, int vid, int handle,
		char *const argv[], char *const envp[], const int *ops);

#endif  /* SRR_PROC_SPAWN_H */
