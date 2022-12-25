/*
 * SRR Kernel: Messages
 *
 * Copyright (c) 2022 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef SRR_MSG_H
#define SRR_MSG_H  1

#include <stddef.h>

/*
 * The function msg_send sends a request to the process.
 *
 * The function msg_receive accepts a request from clients and returns
 * the process identifier of the caller and size of request and answer
 * buffers.
 *
 * The function msg_reply sends an answer to the process for the request
 * previously accepted by msg_receive.
 *
 * The function msg_read reads an extra request data from client request
 * (between msg_receive and msg_reply).
 *
 * The function msg_write writes an extra answer data to client (between
 * msg_receive and msg_reply)
 */
long msg_send (int pid, const void *req, size_t rlen, void *ans, size_t alen);
int  msg_receive (int pid, void *req, size_t *rlen, size_t *alen);

long msg_read  (int pid, size_t offset, void *req, size_t len);
long msg_write (int pid, size_t offset, const void *ans, size_t len);
long msg_reply (int pid, long ret, const void *ans, size_t alen);

#endif  /* SRR_MSG_H */
