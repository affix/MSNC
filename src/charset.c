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

#include "charset.h"
#include "common.h"

#ifdef HAVE_ICONV
#include <iconv.h>

iconv_t from_cd;
iconv_t to_cd;
char *codeset = "ISO-8859-1";

int
iconv_init(cset)
   char *cset;
{
    if (cset[0] != '\0')
        codeset = cset;

    if ((from_cd = iconv_open(codeset, "UTF-8")) == (iconv_t) - 1)
        return -1;
    if ((to_cd = iconv_open("UTF-8", codeset)) == (iconv_t) - 1)
        return -1;

#ifdef DEBUG
    debug_log("Iconv codeset: %s\n", codeset);
#endif

    return 0;
}

void
iconv_destroy()
{
    iconv_close(from_cd);
    iconv_close(to_cd);
}

int
convert(cd, ibuf, isize, obuf, osize)
     iconv_t cd;
     char *ibuf;
     size_t isize;
     char *obuf;
     size_t osize;
{
    int rc = 0;
    char *iptr = ibuf, *optr = obuf;
    size_t oleft = osize, ileft = isize;

    if (strcmp(codeset, "UTF-8") == 0) {
        strncpy(obuf, ibuf, osize - 1);
        return 0;
    }
    memset(obuf, 0x0, osize);

    while (ileft > 0 && oleft > 0) {
        rc = iconv(cd, &iptr, &ileft, &optr, &oleft);
        if (rc == -1) {
            *iptr = '#';
            iptr++;
            ileft--;
        }
    }

    return rc;
}

int
convert_from_utf8(ibuf, isize, obuf, osize)
     char *ibuf;
     size_t isize;
     char *obuf;
     size_t osize;
{
    return convert(from_cd, ibuf, isize, obuf, osize);
}

int
convert_to_utf8(ibuf, isize, obuf, osize)
     char *ibuf;
     size_t isize;
     char *obuf;
     size_t osize;
{
    return convert(to_cd, ibuf, isize, obuf, osize);
}
#endif
