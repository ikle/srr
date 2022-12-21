/*
 * SRR Net: Wire Format
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_WIRE_NET_H
#define SRR_WIRE_NET_H  1

#include <stdint.h>

#define NET_PID  2

enum net_code {
	NET_VC_ATTACH,
	NET_VC_DETACH,
	NET_VC_QUERY,
};

#endif  /* SRR_WIRE_NET_H */
