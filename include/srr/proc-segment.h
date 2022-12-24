/*
 * SRR Process Segments
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_PROC_SEGMENT_H
#define SRR_PROC_SEGMENT_H  1

#include <stddef.h>

#include <srr/wire/proc-segment.h>

/*
 * The function proc_segment_alloc allocates a memory segment of the
 * specified size and associates it with the area of the specified file.
 * On success, returns the starting address of the segment.
 *
 * The function proc_segment_free removes the specified memory segment
 * from the process's memory map.
 *
 * The function proc_segment_query queries information about the process
 * memory serment. Succeeds if a memory segment is found whose start
 * address is greater than or equal to the specified one.
 *
 * The function proc_segment_resize changes the size of the process
 * memory segment. The specified address must point into an existing
 * segment or its end. Returns the address of the previous end of the
 * segment.
 */
long proc_segment_alloc (int proc, int pid, long addr, size_t len, int flags,
			 int vid, int handle, uint64_t offset, size_t flen);
int proc_segment_free  (int proc, int pid, long addr, size_t len);
int proc_segment_query (int proc, int pid, long addr,
			struct proc_segment_info *si);
long proc_segment_resize (int proc, int pid, long addr, long delta);

/*
 * The function proc_segment_share declares a memory segment available
 * to another process with the specified permissions.
 *
 * The function proc_segment_take maps another process's memory segment
 * into its own address space with the specified permissions. Note that
 * the specified address is the address in the space of the source
 * process. On success, returns the starting address of the received
 * segment.
 */
int proc_segment_share (int proc, int pid, long addr, size_t len,
			int with, int flags);
long proc_segment_take (int proc, int pid, long addr, size_t len,
			int from, int flags);

#endif  /* SRR_PROC_SEGMENT_H */
