/*
 * Marten Process Multi-Category Security: Wire Format
 *
 * Copyright (c) 2022-2023 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef PROC_WIRE_MCS_H
#define PROC_WIRE_MCS_H  1

#include <proc/wire/core.h>

struct proc_mcs_setcats {
	int32_t code, pid;
	int64_t cats;
};

struct proc_mcs_getcats {
	int32_t code, pid;
};

#endif  /* PROC_WIRE_MCS_H */
