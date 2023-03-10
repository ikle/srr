/*
 * SRR Process Control
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_PROC_CONTROL_H
#define SRR_PROC_CONTROL_H  1

#include <stddef.h>

#include <srr/wire/proc.h>

/*
 * Functions that change the value of process parameters always return
 * the value before the change. Specify -1 as a parameter if you only
 * want to read the current value.
 */
enum proc_op {
	PROC_TARGET	= 0,		/* select target process	*/

	PROC_FILE	= 20,		/* select file for later ops	*/
	PROC_DUP	= 21,		/* dup file or dup2 to selected	*/
	PROC_CLOSE	= 22, 		/* close file			*/
	PROC_CLOSEFROM	= 23,		/* close set of files		*/
};

/*
 * The function proc_control executes a sequence of count simple single
 * operand commands atomically: if at least one command cannot be
 * executed, then no command at all will be executed.
 *
 * On success returns a copy of the request with the arguments replaced
 * by the results.
 */
int proc_control (int proc, const int32_t *req, int32_t *ans, size_t count);

#endif  /* SRR_PROC_CONTROL_H */
