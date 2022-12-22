/*
 * SRR Net Virtual Circuits: Wire Format
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_WIRE_NET_VC_H
#define SRR_WIRE_NET_VC_H  1

#include <srr/wire/net.h>

struct net_vc_attach {
	int32_t code, nid, pid, len, flags, pad;
};

struct net_vc_detach {
	int32_t code, vid;
};

struct net_vc_query {
	int32_t code, vid;
};

struct net_vc_info {
	int32_t nid, pid, len, flags;
};

#endif  /* SRR_WIRE_NET_VC_H */
