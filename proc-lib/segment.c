/*
 * Marten Process Segments
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <srr/msg.h>
#include <marten/proc/segment.h>

long proc_segment_alloc (int proc, int pid, long addr, size_t len, int flags,
			 int vid, int handle, uint64_t offset, size_t flen)
{
	struct proc_segment_alloc req;

	req.code   = PROC_SEGMENT_ALLOC;
	req.pid    = pid;
	req.addr   = addr;
	req.len    = len;
	req.offset = offset;
	req.flen   = flen;
	req.vid    = vid;
	req.handle = handle;
	req.flags  = flags;
	req.pad    = 0;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_segment_free (int proc, int pid, long addr, size_t len)
{
	struct proc_segment_free req;

	req.code  = PROC_SEGMENT_FREE;
	req.pid   = pid;
	req.addr  = addr;
	req.len   = len;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_segment_query (int proc, int pid, long addr,
			struct proc_segment_info *si)
{
	struct proc_segment_query req;

	req.code  = PROC_SEGMENT_QUERY;
	req.pid   = pid;
	req.addr  = addr;

	return msg_send (proc, &req, sizeof (req), si, sizeof (*si));
}

long proc_segment_resize (int proc, int pid, long addr, long delta)
{
	struct proc_segment_resize req;

	req.code  = PROC_SEGMENT_RESIZE;
	req.pid   = pid;
	req.addr  = addr;
	req.delta = delta;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_segment_share (int proc, int pid, long addr, size_t len,
			int with, int flags)
{
	struct proc_segment_share req;

	req.code  = PROC_SEGMENT_SHARE;
	req.pid   = pid;
	req.flags = flags;
	req.with  = with;
	req.addr  = addr;
	req.len   = len;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

long proc_segment_take  (int proc, int pid, long addr, size_t len,
			int from, int flags)
{
	struct proc_segment_take req;

	req.code  = PROC_SEGMENT_TAKE;
	req.pid   = pid;
	req.flags = flags;
	req.from  = from;
	req.addr  = addr;
	req.len   = len;

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}
