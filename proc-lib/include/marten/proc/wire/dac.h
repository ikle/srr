/*
 * Marten Process Discretionary Access Control: Wire Format
 *
 * Copyright (c) 2022-2023 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef MARTEN_PROC_WIRE_DAC_H
#define MARTEN_PROC_WIRE_DAC_H  1

#include <marten/proc/wire/core.h>

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

#endif  /* MARTEN_PROC_WIRE_DAC_H */
