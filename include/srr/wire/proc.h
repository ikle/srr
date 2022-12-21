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

	PROC_NAME_ATTACH	= 0x80,
	PROC_NAME_DETACH,
	PROC_NAME_LOOKUP,
	PROC_NAME_QUERY,

	PROC_FILE_ATTACH	= 0x90,
	PROC_FILE_DETACH,
	PROC_FILE_QUERY,
};

#endif  /* SRR_WIRE_PROC_H */
