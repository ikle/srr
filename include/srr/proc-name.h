/*
 * SRR Process Names
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_PROC_NAME_H
#define SRR_PROC_NAME_H  1

#include <stddef.h>
#include <stdint.h>

struct proc_name_info {
	int32_t pid, uid, gid, mode;
	char name[];
};

/*
 * The function proc_name_attach creates a name with the specified access
 * rights. Returns the identifier of the name. Requires write access to
 * the proc process.
 *
 * The function proc_name_detach removes the name. Requires write access
 * to the proc process.
 *
 * The function proc_name_lookup looks up the name. Returns the pid of the
 * process that owns the name. Requires read access to the proc process.
 *
 * The function proc_name_query queries the name info. Returns information
 * about the name with an identifier equal to the specified one or, if
 * none, with the next identifier. Returns the name identifier. Requires
 * read access to the proc process.
 */
int proc_name_attach (int pid, const char *name, int uid, int gid, int mode);
int proc_name_detach (int pid, int id);

int proc_name_lookup (int pid, const char *name);
int proc_name_query  (int pid, int id, struct proc_name_info *ni, size_t size);

#endif  /* SRR_PROC_NAME_H */
