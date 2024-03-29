/*
 * Marten Process Segments: Wire Format
 *
 * Copyright (c) 2022-2023 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef MARTEN_PROC_WIRE_SEGMENT_H
#define MARTEN_PROC_WIRE_SEGMENT_H  1

#include <marten/proc/wire/core.h>

/* manage process memory map */

struct proc_segment_info {
	uint64_t addr, len, offset, flen;
	uint32_t vid, handle, flags, pad;
};

struct proc_segment_alloc {  /* mmap */
	int32_t  code, pid;
	uint64_t addr, len, offset, flen;
	uint32_t vid, handle, flags, pad;
};

struct proc_segment_free {  /* munmap */
	int32_t  code, pid;
	uint64_t addr, len;
};

struct proc_segment_query {  /* search for seg.addr >= addr */
	int32_t  code, pid;
	uint64_t addr;
};

struct proc_segment_resize {
	int32_t  code, pid;
	uint64_t addr;
	int64_t  delta;
};

/* manage process memory share map */

struct proc_segment_share {
	int32_t code, pid, flags, with;
	uint64_t addr, len;
};

struct proc_segment_take {
	int32_t code, pid, flags, from;
	uint64_t addr, len;
};

#endif  /* MARTEN_PROC_WIRE_SEGMENT_H */
