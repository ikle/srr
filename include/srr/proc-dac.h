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
 */
int proc_dac_setids  (int proc, int pid, int uid, int gid);
int proc_dac_setmask (int proc, int pid, int active, int family);
int proc_dac_query   (int proc, int pid, struct proc_dac_info *di);

#endif  /* SRR_PROC_DAC_H */
