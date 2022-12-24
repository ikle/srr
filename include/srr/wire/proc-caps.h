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

enum proc_caps {
	CAP_PROC_SCHED		= 1 << 0x2,
	CAP_PROC_CAPS		= 1 << 0x3,
	CAP_PROC_DAC		= 1 << 0x4,
	CAP_PROC_MLS		= 1 << 0x5,
	CAP_PROC_MCS		= 1 << 0x6,
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

#endif  /* SRR_WIRE_PROC_CAPS_H */
