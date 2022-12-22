/*
 * SRR Net Virtual Circuits
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <srr/msg.h>
#include <srr/net-vc.h>
#include <srr/proc-name.h>

int net_vc_attach (int nid, int pid, int len, int flags)
{
	struct net_vc_attach req;

	req.code  = NET_VC_ATTACH;
	req.nid   = nid;
	req.pid   = pid;
	req.len   = len;
	req.flags = flags;

	return msg_send (NET_PID, &req, sizeof (req), NULL, 0);
}

int net_vc_detach (int vid)
{
	struct net_vc_detach req;

	req.code  = NET_VC_DETACH;
	req.vid   = vid;

	return msg_send (NET_PID, &req, sizeof (req), NULL, 0);
}

int net_vc_connect (int nid, const char *name, int len, int flags)
{
	int proc, pid;

	if (nid == 0) {
		if ((pid = proc_name_lookup (PROC_PID, name)) < 0)
			return pid;

		return net_vc_attach (nid, pid, len, flags);
	}

	if ((proc = net_vc_attach (nid, PROC_PID, 0, 0)) < 0)
		return proc;

	if ((pid = proc_name_lookup (proc, name)) >= 0)
		pid = net_vc_attach (nid, pid, len, flags);

	net_vc_detach (proc);
	return pid;

}

int net_vc_query (int vid, struct net_vc_info *vi)
{
	struct net_vc_query req;

	req.code  = NET_VC_QUERY;
	req.vid   = vid;

	return msg_send (NET_PID, &req, sizeof (req), vi, sizeof (*vi));
}
