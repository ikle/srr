/*
 * SRR Net Virtual Circuits
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_NET_VC_H
#define SRR_NET_VC_H  1

#include <stdint.h>

struct net_vc_info {
	int32_t nid, pid, len, flags;
};

/*
 * The virtual circuit process is a message proxy process (forked from
 * the net process) reparented and reowned to the caller process.
 *
 * The function net_vc_attach establishes a connection to the remote
 * process pid on node nid. Returns the pid of the gateway process.
 * Requires execute access to the net process.
 *
 * The function net_vc_detach closes the connection to the remote
 * process. Requires write access to the virtual circuit process.
 *
 * The function net_vc_connect looks up a remote process by name and
 * establishes a connection to it. Returns the pid of the gateway
 * process. Requires execute access to the net process.
 *
 * The function net_vc_query looks up information about the virtual
 * process. Returns 0 on success and populates the vi with information
 * about the virtual process.
 */
int net_vc_attach  (int nid, int pid, int len, int flags);
int net_vc_detach  (int vid);
int net_vc_connect (int nid, const char *name, int len, int flags);
int net_vc_query   (int vid, struct net_vc_info *vi);

#endif  /* SRR_NET_VC_H */
