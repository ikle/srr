/*
 * SRR Process Names
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <string.h>

#include <srr/msg.h>
#include <srr/proc-name.h>

int proc_name_attach (int proc, const char *name)
{
	struct proc_name_attach req;

	req.code = PROC_NAME_ATTACH;
	strncpy (req.name, name, sizeof (req.name));

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_name_detach (int proc, const char *name)
{
	struct proc_name_detach req;

	req.code = PROC_NAME_DETACH;
	strncpy (req.name, name, sizeof (req.name));

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_name_lookup (int proc, const char *name)
{
	struct proc_name_lookup req;

	req.code = PROC_NAME_LOOKUP;
	strncpy (req.name, name, sizeof (req.name));

	return msg_send (proc, &req, sizeof (req), NULL, 0);
}

int proc_name_query (int proc, const char *after,
		     struct proc_name_info *ni, size_t count)
{
	struct proc_name_query req;

	req.code = PROC_NAME_QUERY;

	if (after == NULL)
		memset  (req.name, '\0',  sizeof (req.name));
	else
		strncpy (req.name, after, sizeof (req.name));

	return msg_send (proc, &req, sizeof (req), ni, sizeof (*ni) * count);
}
