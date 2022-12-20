/*
 * SRR Process Access Capabilities
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_PROC_CAPS_H
#define SRR_PROC_CAPS_H  1

enum proc_cap {
	PROC_CAP_SCHED	= 0x0001,	/* change scheduling algo	*/
	PROC_CAP_PRIO	= 0x0002,	/* raise scheduling priority	*/

	PROC_CAP_CRED	= 0x0010,	/* change UID and GID		*/
	PROC_CAP_MLS	= 0x0020,	/* change MLS level		*/
	PROC_CAP_MCS	= 0x0040,	/* enlarge MCS categories	*/

	PROC_CAP_GROUP	= 0x0100,	/* regroup process freely	*/
};

#endif  /* SRR_PROC_CAPS_H */
