/*
 * Marten Process Capabilities: Wire Format
 *
 * Copyright (c) 2022-2023 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef MARTEN_PROC_WIRE_CAPS_H
#define MARTEN_PROC_WIRE_CAPS_H  1

#include <marten/proc/wire/core.h>

enum proc_caps {
	CAP_PROC_SEGMENT	= 1 << 0x1,
	CAP_PROC_SCHED		= 1 << 0x2,
	CAP_PROC_CAPS		= 1 << 0x3,
	CAP_PROC_DAC		= 1 << 0x4,
	CAP_PROC_GROUP		= 1 << 0x7,
	CAP_PROC_NAME		= 1 << 0x8,	/* cluster service	*/
	CAP_PROC_FILE		= 1 << 0x9,
	CAP_PROC_CLOCK		= 1 << 0xa,

	CAP_NET_ADMIN		= 1 << 0x10,
	CAP_NET_SERVICE		= 1 << 0x11,	/* global net service	*/
	CAP_NET_CLIENT		= 1 << 0x12,	/* global net client	*/
};

struct proc_caps_setmask {
	int32_t code, pid, active, family;
};

struct proc_caps_info {
	int32_t active, family;  /* inherited = active & family */
};

struct proc_caps_query {
	int32_t code, pid;
};

#endif  /* MARTEN_PROC_WIRE_CAPS_H */
