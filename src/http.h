#ifndef _HTTP_H
#define _HTTP_H

#include <strings.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "rio.h"
#include "list.h"
#include "dbg.h"
#include "http_request.h"
   
#define MAX_BUF 8124

#define CR '\r'
#define LF '\n'
#define CRLFCRLF "\r\n\r\n"

#define MAXLINE 8192
#define SHORTLINE 512
#define root "/home/zjs/macHome/lifeofzjs/public"

#define zv_str3_cmp(m, c0, c1, c2, c3)                                       \
    *(uint32_t *) m == ((c3 << 24) | (c2 << 16) | (c1 << 8) | c0)
#define zv_str3Ocmp(m, c0, c1, c2, c3)                                       \
    *(uint32_t *) m == ((c3 << 24) | (c2 << 16) | (c1 << 8) | c0)

#define zv_str4cmp(m, c0, c1, c2, c3)                                        \
    *(uint32_t *) m == ((c3 << 24) | (c2 << 16) | (c1 << 8) | c0)


typedef struct mime_type_s {
	const char *type;
	const char *value;
} mime_type_t;

const char* get_file_type(const char *type);
void do_request(void *infd);
void parse_uri(char *uri, int length, char *filename, char *querystring);
void do_error(int fd, char *cause, char *errnum, char *shortmsg, char *longmsg);
void serve_static(int fd, char *filename, int filesize);

#endif
