/*
 * SRR Process Multi-Category Security
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_PROC_MCS_H
#define SRR_PROC_MCS_H  1

#include <srr/wire/proc-mcs.h>

/*
 * The function proc_mcs_setcat sets the set of process MCS categories.
 * Note that unprivileged processes can only exit categories (reduce the
 * active set).
 *
 * The function always succeeds, setting the active category set for
 * unprivileged processes to the intersection of the current set and the
 * requested one. For privileged processes, the active category set is
 * replaced by the requested one.
 *
 * The function proc_mcs_getcat queries the current set of process MCS
 * categories.
 */
int proc_mcs_setcat (int proc, int pid, const int32_t *cat, size_t count);
int proc_mcs_getcat (int proc, int pid, int32_t *cat, size_t count);

#endif  /* SRR_PROC_MCS_H */
