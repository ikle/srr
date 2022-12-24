/*
 * SRR Process: Wire Format
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_WIRE_PROC_H
#define SRR_WIRE_PROC_H  1

#include <stdint.h>

#define PROC_PID  1

enum proc_code {
	PROC_CONTROL_OPS	= 0x00,

	PROC_SCHED_CONFIG	= 0x20,
	PROC_SCHED_QUERY,
	PROC_SCHED_NICE,
	PROC_SCHED_YIELD,

	PROC_CAPS_SETMASK	= 0x30,
	PROC_CAPS_QUERY,

	PROC_DAC_SETIDS		= 0x40,
	PROC_DAC_SETMASK,
	PROC_DAC_QUERY,

	PROC_MLS_SETLEVEL	= 0x50,
	PROC_MLS_GETLEVEL,

	PROC_MCS_SETCATS	= 0x60,
	PROC_MCS_GETCATS,

	PROC_GROUP_STEAL	= 0x70,
	PROC_GROUP_ADOPT,
	PROC_GROUP_LEAD,
	PROC_GROUP_CHAIR,
	PROC_GROUP_QUERY,

	PROC_NAME_ATTACH	= 0x80,
	PROC_NAME_DETACH,
	PROC_NAME_LOOKUP,
	PROC_NAME_QUERY,

	PROC_FILE_ATTACH	= 0x90,
	PROC_FILE_DETACH,
	PROC_FILE_QUERY,

	PROC_CLOCK_GETTIME	= 0xa0,
	PROC_CLOCK_SETTIME,
	PROC_CLOCK_ADJTIME,
};

#endif  /* SRR_WIRE_PROC_H */
