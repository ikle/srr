/*
 * Marten Process Multi-Level Security: Wire Format
 *
 * Copyright (c) 2022-2023 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef PROC_WIRE_MLS_H
#define PROC_WIRE_MLS_H  1

#include <proc/wire/core.h>

/*
 * new mls.read  = current mls.read  & requested mls.read
 * new mls.write = current mls.write & requested mls.write
 *
 * Returns -EPERM if any new level mask is zero.
 */
struct proc_mls_setlevel {
	int32_t code, pid, read, write;  /* read and write level masks */
};

struct proc_mls_info {
	int32_t read, write;
};

struct proc_mls_getlevel {
	int32_t code, pid;
};

#endif  /* PROC_WIRE_MLS_H */
