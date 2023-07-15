/*
 * Marten Process Multi-Category Security: Wire Format
 *
 * Copyright (c) 2022-2023 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef MARTEN_PROC_WIRE_MCS_H
#define MARTEN_PROC_WIRE_MCS_H  1

#include <marten/proc/wire/core.h>

/*
 * 1. Family set is a set of allowed categories. Can only be reduced.
 * 2. Active set is a set of current active categories. Can only be
 *    a subset of family set.
 */

/*
 * next mcs.family = current mcs.family & requested mcs.family
 * next mcs.active = requested mcs.active & next mcs.family
 *
 * Returns -EPERM if next mcs.family is zero.
 */
struct proc_mcs_setcats {
	int32_t code, pid;
	int64_t active, family;
};

struct proc_mcs_info {
	int64_t active, family;
};

struct proc_mcs_getcats {
	int32_t code, pid;
};

#endif  /* MARTEN_PROC_WIRE_MCS_H */
