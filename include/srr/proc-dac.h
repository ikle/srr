/*
 * SRR Process Discretionary Access Control
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_PROC_DAC_H
#define SRR_PROC_DAC_H  1

#include <srr/wire/proc-dac.h>

/*
 * The function proc_dac_setids changes the user and/or group ID.
 *
 * The function proc_dac_setmask sets masks for maximum and inherited
 * file access rights.
 *
 * The function proc_dac_query queries information about the primary
 * DAC parameters.
 *
 * The function proc_dac_setgroups sets the set of supplementary groups
 * of the process.
 *
 * The function proc_dac_getgroups returns the set of supplementary
 * groups of the process.
 */
int proc_dac_setids  (int proc, int pid, int uid, int gid);
int proc_dac_setmask (int proc, int pid, int active, int family);
int proc_dac_query   (int proc, int pid, struct proc_dac_info *di);

int proc_dac_setgroups (int proc, int pid, const int32_t *gid, size_t count);
int proc_dac_getgroups (int proc, int pid, int32_t *gid, size_t count);

#endif  /* SRR_PROC_DAC_H */
