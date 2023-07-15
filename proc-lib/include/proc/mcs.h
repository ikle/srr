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
 * Note that unprivileged processes can only exit categories (reduce the
 * active set).
 *
 * The function always succeeds, setting the active category set for
 * unprivileged processes to the intersection of the current set and the
 * requested one. For privileged processes, the active category set is
 * replaced by the requested one.
 *
 * The function proc_mcs_getcats queries the current set of process MCS
 * categories.
 */
int proc_mcs_setcats (int proc, int pid, int64_t  cats);
int proc_mcs_getcats (int proc, int pid, int64_t *cats);

#endif  /* PROC_MCS_H */
