/*
 * SRR Process Multi-Level Security
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_PROC_MLS_H
#define SRR_PROC_MLS_H  1

#include <srr/wire/proc-mls.h>

/*
 * The function proc_mls_setlevel sets the MLS access level. Returns 0
 * on success.
 *
 * The function proc_mls_getlevel queries the MLS access level. Returns
 * current access level.
 */
int proc_mls_setlevel (int proc, int pid, int read, int write);
int proc_mls_getlevel (int proc, int pid);

#endif  /* SRR_PROC_MLS_H */
