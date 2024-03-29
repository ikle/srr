/*
 * Marten Process Core
 *
 * Copyright (c) 2022-2023 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef MARTEN_PROC_PROCESS_H
#define MARTEN_PROC_PROCESS_H  1

#include <marten/proc/wire/process.h>

/*
 * The function proc_process_alloc creates a new empty process. On
 * success, returns the identifier of the new process.
 *
 * The function proc_process_free kills the specified process. Returns 0
 * on success.
 */
int proc_process_alloc (int proc, int flags);
int proc_process_free  (int proc, int pid);

#endif  /* MARTEN_PROC_PROCESS_H */
