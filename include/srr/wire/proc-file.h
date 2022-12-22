/*
 * SRR Process File Descriptors: Wire Format
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_WIRE_PROC_FILE_H
#define SRR_WIRE_PROC_FILE_H  1

#include <srr/wire/proc.h>

struct proc_file_attach {
	int32_t code, fd, nid, pid, vid, handle, flags, pad;
};

struct proc_file_detach {
	int32_t code, fd;
};

struct proc_file_query {
	int32_t code, pid, fd, pad;
};

enum proc_file_flag {
	PROC_FILE_PRIVATE	= 0x01,	/* do not copy to childs */
};

/*
 * If the resource is on the local node then nid = 0, vid = pid.
 */
struct proc_file_info {
	int32_t nid, pid, vid, handle;	/* resource location */
	int32_t flags;
};

#endif  /* SRR_WIRE_PROC_FILE_H */
