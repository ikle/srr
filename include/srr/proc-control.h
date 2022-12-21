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

/*
 * Functions that change the value of process parameters always return
 * the value before the change. Specify -1 as a parameter if you only
 * want to read the current value.
 */
enum proc_op {
	PROC_SCHED	= 1,		/* scheduler algorithm		*/
	PROC_PRIO	= 2,		/* process priority		*/

	PROC_CAPS	= 4,		/* process capabilities		*/
	PROC_UID	= 5,		/* process owner		*/
	PROC_GID	= 6,		/* process group		*/
	PROC_MODE	= 7,		/* access to process and umask	*/
	PROC_MLS	= 8,		/* MLS level			*/
	PROC_MCS	= 9,		/* MCS categories		*/

	PROC_PID	= 10,		/* process identifier		*/
	PROC_PPID	= 11,		/* parent process		*/
	PROC_PGRP	= 12,		/* process group		*/
	PROC_SID	= 13,		/* session leader		*/

	PROC_FILE	= 20,		/* select file for later ops	*/
	PROC_DUP	= 21,		/* dup file or dup2 to selected	*/
	PROC_CLOSE	= 22, 		/* close file			*/
	PROC_CLOSEFROM	= 23,		/* close set of files		*/
};

/*
 * The function proc_control executes a zero-terminated sequence of simple
 * commands atomically: if at least one command cannot be executed, then
 * no command at all will be executed.
 *
 * On success returns a copy of the request with the arguments replaced
 * by the results.
 */
int proc_control (int proc, int pid, const int *req, int *ans, size_t size);

#endif  /* SRR_PROC_CONTROL_H */
