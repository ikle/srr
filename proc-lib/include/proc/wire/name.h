/*
 * Marten Process Names: Wire Format
 *
 * Copyright (c) 2022-2023 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef PROC_WIRE_NAME_H
#define PROC_WIRE_NAME_H  1

#include <proc/wire/core.h>

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
	char name[20];
};

#endif  /* PROC_WIRE_NAME_H */
