/*
 * SRR Process File Descriptors
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_PROC_FILE_H
#define SRR_PROC_FILE_H  1

enum proc_file_flag {
	PROC_FILE_PRIVATE	0x01,	/* do not copy to childs	*/
};

/*
 * If the resource is on the local node then nid = 0, vid = pid.
 */
struct proc_file_info {
	int nid, pid, vid, handle;	/* resource location		*/
	int flags;
};

/*
 * Sharing files on spawn to a new process (fork or fork + exec):
 *
 * 1. Proc copies file table to new process from parent.
 * 2. Proc creates child process stopped.
 * 3. Parent after spawn to a new process share files with his child.
 * 4. Parent starts new child.
 * 5. Child init code queries files from Proc and takes them (share on exec).
 * 6. Child after fork queries files from Proc and takes them.
 *
 * All this work is hidden from the user inside the proc_spawn and
 * proc_init functions.
 */

/*
 * The function proc_file_attach registers the resource as a process
 * file. The search for a free file descriptor starts with fd. Returns
 * the allocated file descriptor on success.
 *
 * The function proc_file_detach unregisters a resource as a file.
 * Returns 0 on success.
 *
 * The function proc_file_query searches for a file starting at
 * descriptor fd. If successful, returns the file descriptor of the
 * found file and information about the file resource in the fi.
 */
int proc_file_attach (int fd, int nid, int pid, int vid, int handle, int flags);
int proc_file_detach (int fd);
int proc_file_query  (int proc, int pid, int fd, struct proc_file_info *fi);

#endif  /* SRR_PROC_FILE_H */
