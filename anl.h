/* Copyright (C) 2001, 2006 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@redhat.com>, 2001.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#ifndef ANL_H
#define ANL_H

#include <netdb.h>
#include <signal.h>
#include <time.h>

#undef gaicb
#undef getaddrinfo_a
#undef gai_suspend
#undef gai_error
#undef gai_cancel

#ifndef __USE_GNU
#define __ANL_S_HDR
#endif

#ifdef __ANL_S_HDR

struct gaicb {
    const char *ar_name; /* Name to look up.  */
    const char *ar_service; /* Service name.  */
    const struct addrinfo *ar_request; /* Additional request specification.  */
    struct addrinfo *ar_result; /* Pointer to result.  */
    /* The following are internal elements.  */
    int __return;
    int __glibc_reserved[5];
};

#define GAI_WAIT	0
#define GAI_NOWAIT	1

#define EAI_NODATA	  -5	/* No address associated with NAME.  */
#define EAI_ADDRFAMILY  -9	/* Address family for NAME not supported.  */
#define EAI_INPROGRESS  -100	/* Processing request in progress.  */
#define EAI_CANCELED	  -101	/* Request canceled.  */
#define EAI_NOTCANCELED -102	/* Request not canceled.  */
#define EAI_ALLDONE	  -103	/* All requests done.  */
#define EAI_INTR	  -104	/* Interrupted by a signal.  */
#define EAI_IDN_ENCODE  -105	/* IDN encoding failed.  */

#endif

int __anl_s_getaddrinfo_a(int mode, struct gaicb *list[],
        int nitems, struct sigevent *sevp);

int __anl_s_gai_suspend(const struct gaicb *list[], int nitems,
        struct timespec *timeout);

int __anl_s_gai_error(struct gaicb *req);

int __anl_s_gai_cancel(struct gaicb *req);

#define getaddrinfo_a(mode, list, nitems, sevp) __anl_s_getaddrinfo_a(mode, list, nitems, sevp)
#define gai_suspend(list, nitems, timeout) __anl_s_gai_suspend(list, nitems, timeout)
#define gai_error(req) __anl_s_gai_error(req)
#define gai_cancel(req) __anl_s_gai_cancel(req)

#endif
