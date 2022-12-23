/*
 * SRR Process Capabilities: Wire Format
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_WIRE_PROC_CAPS_H
#define SRR_WIRE_PROC_CAPS_H  1

#include <srr/wire/proc.h>

struct proc_caps_setmask {
	int32_t code, pid, active, family;
};

struct proc_caps_info {
	int32_t active, family;  /* inherited = active & family */
};

struct proc_caps_query {
	int32_t code, pid;
};

#endif  /* SRR_WIRE_PROC_CAPS_H */
