/*
 * SRR Process Groupping: Wire Format
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_WIRE_PROC_GROUP_H
#define SRR_WIRE_PROC_GROUP_H  1

#include <srr/wire/proc.h>

/* family level */

struct proc_group_steal {
	int32_t code, pid, victim, pad;  /* change pid */
};

struct proc_group_adopt {
	int32_t code, pid, parent, pad;  /* change ppid */
};

/* social level */

struct proc_group_lead {
	int32_t code, pid;  /* become a group leader */
};

struct proc_group_chair {
	int32_t code, pid;  /* become a session leader */
};

/* process identity */

struct proc_group_info {
	int32_t pid, ppid, pgrp, sid;
};

struct proc_group_query {
	int32_t code, pid;
};

#endif  /* SRR_WIRE_PROC_GROUP_H */
