/*
 * Marten Process Multi-Level Security
 *
 * Copyright (c) 2022-2023 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef MARTEN_PROC_MLS_H
#define MARTEN_PROC_MLS_H  1

#include <marten/proc/wire/mls.h>

/*
 * The function proc_mls_setlevel sets the MLS access level masks to
 * intersection of current level masks with requested ones. Returns -EPERM
 * if any new level mask is zero. Returns 0 on success.
 *
 * The function proc_mls_getlevel queries the MLS access level masks.
 * Returns 0 on success.
 */
int proc_mls_setlevel (int proc, int pid, int read, int write);
int proc_mls_getlevel (int proc, int pid, struct proc_mls_info *mi);

#endif  /* MARTEN_PROC_MLS_H */
