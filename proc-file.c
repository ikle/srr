/*
 * SRR Process File Descriptors
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <srr/msg.h>
#include <srr/net-vc.h>
#include <srr/proc-file.h>

int proc_file_attach (int fd, int nid, int pid, int vid, int handle, int flags)
{
	struct net_vc_info vi;
	struct proc_file_attach req;

	if (nid == 0) {
		if (pid == 0) {
			if (net_vc_query (vid, &vi) < 0)
				pid = vid;
			else {
				nid = vi.nid;
				pid = vi.pid;
			}
		}
		else
			vid = pid;
	}
	else {
		if (vid == 0 && (vid = net_vc_attach (nid, pid, 0, 0)) < 0)
			return vid;
	}

	req.code   = PROC_FILE_ATTACH;
	req.fd     = fd;
	req.nid    = nid;
	req.pid    = pid;
	req.vid    = vid;
	req.handle = handle;
	req.flags  = flags;

	return msg_send (PROC_PID, &req, sizeof (req), NULL, 0);
}

int proc_file_detach (int fd)
{
	struct proc_file_detach req;

	req.code = PROC_FILE_DETACH;
	req.fd   = fd;

	return msg_send (PROC_PID, &req, sizeof (req), NULL, 0);
}

int proc_file_query (int proc, int pid, int fd, struct proc_file_info *fi)
{
	struct proc_file_query req;

	proc = proc == 0 ? PROC_PID : proc;

	req.code = PROC_FILE_QUERY;
	req.pid  = pid;
	req.fd   = fd;

	return msg_send (proc, &req, sizeof (req), fi, sizeof (*fi));
}
