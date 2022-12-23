/*
 * SRR Process Discretionary Access Control: Wire Format
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_WIRE_PROC_DAC_H
#define SRR_WIRE_PROC_DAC_H  1

#include <srr/wire/proc.h>

struct proc_dac_setids {
	int32_t code, pid, uid, gid;
};

struct proc_dac_setmask {
	int32_t code, pid, active, family;  /* umask = active & family */
};

struct proc_dac_info {
	int32_t uid, gid, active, family;
};

struct proc_dac_query {
	int32_t code, pid;
};

struct proc_dac_setgroups {
	int32_t code, pid;
	int32_t gid[];		/* can be empty */
};

struct proc_dac_getgroups {
	int32_t code, pid;
};

#endif  /* SRR_WIRE_PROC_DAC_H */
