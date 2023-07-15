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

#include <srr/wire/proc-name.h>

/*
 * The function proc_name_attach associates a name with the calling
 * process. Returns 0 on success.
 *
 * The function proc_name_detach removes the name's association with the
 * calling process. Returns 0 on success.
 *
 * The function proc_name_lookup looks up the name. Returns the pid of
 * the process that owns the name.
 *
 * The function proc_name_query queries the name info. Stores information
 * about up to count names after the specified one and returns the number
 * of entries saved. To search from the beginning of the list of names,
 * specify empty string (after = "").
 */
int proc_name_attach (int proc, const char *name);
int proc_name_detach (int proc, const char *name);
int proc_name_lookup (int proc, const char *name);
int proc_name_query  (int proc, const char *after,
		      struct proc_name_info *ni, size_t count);

#endif  /* SRR_PROC_NAME_H */
