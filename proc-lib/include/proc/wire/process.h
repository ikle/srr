/*
 * Marten Process Core: Wire Format
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef PROC_WIRE_PROCESS_H
#define PROC_WIRE_PROCESS_H  1

#include <proc/wire/core.h>

struct proc_process_alloc {
	int32_t code, flags;
};

struct proc_process_free {
	int32_t code, pid;
};

#endif  /* PROC_WIRE_PROCESS_H */
