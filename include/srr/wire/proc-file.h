/*
 * SRR Process File Descriptors: Wire Format
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_WIRE_PROC_FILE_H
#define SRR_WIRE_PROC_FILE_H  1

#include <stdint.h>

#define PROC_PID  1

enum proc_file {
	PROC_FILE_ATTACH,
	PROC_FILE_DETACH,
	PROC_FILE_QUERY,
};

struct proc_file_attach {
	int32_t code, fd, nid, pid, vid, handle, flags;
};

struct proc_file_detach {
	int32_t code, fd;
};

struct proc_file_query {
	int32_t code, pid, fd;
};

#endif  /* SRR_WIRE_PROC_FILE_H */
