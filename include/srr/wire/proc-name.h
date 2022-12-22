/*
 * SRR Process Names: Wire Format
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_WIRE_PROC_NAME_H
#define SRR_WIRE_PROC_NAME_H  1

#include <srr/wire/proc.h>

struct proc_name_attach {
	int32_t code;
	char name[20];
};

struct proc_name_detach {
	int32_t code;
	char name[20];
};

struct proc_name_lookup {
	int32_t code;
	char name[20];
};

struct proc_name_query {
	int32_t code;
	char name[20];
};

struct proc_name_info {
	int32_t pid;
	char name[16];
};

#endif  /* SRR_WIRE_PROC_NAME_H */
