/*
 * Marten Process Core: Wire Format
 *
 * Copyright (c) 2022-2023 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef MARTEN_PROC_WIRE_PROCESS_H
#define MARTEN_PROC_WIRE_PROCESS_H  1

#include <marten/proc/wire/core.h>

struct proc_process_alloc {
	int32_t code, flags;
};

struct proc_process_free {
	int32_t code, pid;
};

#endif  /* MARTEN_PROC_WIRE_PROCESS_H */
