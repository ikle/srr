/*
 * SRR Process Multi-Level Security: Wire Format
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_WIRE_PROC_MLS_H
#define SRR_WIRE_PROC_MLS_H  1

#include <srr/wire/proc.h>

struct proc_mls_setlevel {
	int32_t code, pid, level, pad;
};

struct proc_mls_getlevel {
	int32_t code, pid;
};

#endif  /* SRR_WIRE_PROC_MLS_H */
