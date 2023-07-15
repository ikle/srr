/*
 * Marten Process Capabilities
 *
 * Copyright (c) 2022-2023 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef MARTEN_PROC_CAPS_H
#define MARTEN_PROC_CAPS_H  1

#include <marten/proc/wire/caps.h>

/*
 * The function proc_caps_config sets the active and inherited
 * capabilities of a process. Returns 0 on success.
 *
 * The function proc_caps_query queries the capabilities of the process.
 * Returns 0 on success.
 */
int proc_caps_setmask (int proc, int pid, int active, int family);
int proc_caps_query   (int proc, int pid, struct proc_caps_info *ci);

#endif  /* MARTEN_PROC_CAPS_H */
