/*
 * SRR Process Names
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <stdarg.h>
#include <stdio.h>

#include <srr/msg.h>
#include <srr/proc-name.h>

#include <srr/wire/proc-name.h>

static int proc_name_req_va (int proc, int code, const char *fmt, va_list ap)
{
	struct proc_name_req req;

	req.code = code;
	vsnprintf (req.name, sizeof (req.name), fmt, ap);

	return msg_send (PROC_PID, &req, sizeof (req), NULL, 0);
}

int proc_name_attach (int proc, const char *fmt, ...)
{
	va_list ap;
	int ret;

	va_start (ap, fmt);
	ret = proc_name_req_va (proc, PROC_NAME_ATTACH, fmt, ap);
	va_end (ap);

	return ret;
}

int proc_name_detach (int proc, const char *fmt, ...)
{
	va_list ap;
	int ret;

	va_start (ap, fmt);
	ret = proc_name_req_va (proc, PROC_NAME_DETACH, fmt, ap);
	va_end (ap);

	return ret;
}

int proc_name_lookup (int proc, const char *fmt, ...)
{
	va_list ap;
	int ret;

	va_start (ap, fmt);
	ret = proc_name_req_va (proc, PROC_NAME_LOOKUP, fmt, ap);
	va_end (ap);

	return ret;
}

int proc_name_query (int proc, const char *after,
		     struct proc_name_info *ni, size_t count)
{
	struct proc_name_req req;

	req.code = PROC_NAME_QUERY;

	if (after == NULL)
		req.name[0] = '\0';
	else
		snprintf (req.name, sizeof (req.name), "%s", after);

	return msg_send (PROC_PID, &req, sizeof (req),
			 ni, sizeof (*ni) * count);
}
