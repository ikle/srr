/*
 * Marten Process Multi-Category Security
 *
 * Copyright (c) 2022-2023 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef PROC_MCS_H
#define PROC_MCS_H  1

#include <proc/wire/mcs.h>

/*
 * The function proc_mcs_setcats sets the set of process MCS categories.
 * The function sets the family category set to the intersection of the
 * current family set and the requested one. The active category set
 * replaced by the intersection of the new family set and the requested
 * active set. Returns -EPERM if new family set is zero, 0 otherwise.
 *
 * The function proc_mcs_getcats queries the current set of process MCS
 * categories.
 */
int proc_mcs_setcats (int proc, int pid, int64_t active, int64_t family);
int proc_mcs_getcats (int proc, int pid, struct proc_mcs_info *mi);

#endif  /* PROC_MCS_H */
