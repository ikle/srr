/*
 * SRR Process Multi-Category Security: Wire Format
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_WIRE_PROC_MCS_H
#define SRR_WIRE_PROC_MCS_H  1

#include <srr/wire/proc.h>

struct proc_mcs_setcat {
	int32_t code, pid;
	int32_t cat[];		/* can be empty */
};

struct proc_mcs_getcat {
	int32_t code, pid;
};

#endif  /* SRR_WIRE_PROC_MCS_H */
