/*
This file is part of MSNC.

Copyright (C) 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002,
2003, 2004, 2005  Free Software Foundation, Inc.
This Makefile.in is free software; the Free Software Foundation
gives unlimited permission to copy and/or distribute it,
with or without modifications, as long as this notice is preserved.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY, to the extent permitted by law; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.

MSNC is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

MSNC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TRANSFERS 20

#define STATE_NEGOTIATE 1
#define STATE_CONNECT   2
#define STATE_DOWNLOAD  3
#define STATE_UPLOAD    4
#define STATE_COMPLETE  5
#define STATE_CANCEL    6
#define STATE_ERROR     7

#define DWORD unsigned int
#define QWORD unsigned long long

struct p2p_transfer {
    char *from, *ip;
    int sd, state;
    QWORD size, offset;
};

struct p2p_header {
    DWORD sid;
    DWORD b_ident;
    QWORD offset;
    QWORD tot_len;
    DWORD msg_len;
    DWORD flag;
    DWORD ack_ident;
    DWORD ack_uid;
    QWORD ack_tot_len;
};

#define INVITE 1
#define BYE    2

struct msg_header {
    char *to, *from, *cid, *ctype;
    int method, cseq, max_forward, clen;
};
