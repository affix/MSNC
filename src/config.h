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
/* src/config.h.  Generated from config.h.in by configure.  */
/* src/config.h.in.  Generated from configure.in by autoheader.  */

/* Found some version of curses that we're going to use */
#define HAS_CURSES 1

/* Define if you have the iconv() function. */
#define HAVE_ICONV 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `nsl' library (-lnsl). */
/* #undef HAVE_LIBNSL */

/* Define to 1 if you have the `socket' library (-lsocket). */
/* #undef HAVE_LIBSOCKET */

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* openssl executable path */
#define HAVE_OPENSSL 1

/* Define to 1 if you have the `resizeterm' function. */
#define HAVE_RESIZETERM 1

/* Define to 1 if you have the `resize_term' function. */
#define HAVE_RESIZE_TERM 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* libtalkfilters */
/* #undef HAVE_TALKFILTERS */

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the `use_default_colors' function. */
#define HAVE_USE_DEFAULT_COLORS 1

/* Define to 1 if you have the `wadd_wch' function. */
/* #undef HAVE_WADD_WCH */

/* Define as const if the declaration of iconv() needs const. */
#define ICONV_CONST 

/* If your curses does not have color define this one */
/* #undef NO_COLOR_CURSES */

/* Name of package */
#define PACKAGE "tmsnc"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME ""

/* Define to the full name and version of this package. */
#define PACKAGE_STRING ""

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME ""

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION ""

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */
#define TIME_WITH_SYS_TIME 1

/* Define to 1 if your <sys/time.h> declares `struct tm'. */
/* #undef TM_IN_SYS_TIME */

/* Use Ncurses? */
#define USE_NCURSES 1

/* Use SunOS SysV curses? */
/* #undef USE_SUNOS_CURSES */

/* Use SystemV curses? */
/* #undef USE_SYSV_CURSES */

/* Version number of package */
#define VERSION "0.3.2"

/* curses routines to work with wide chars are available */
/* #undef WIDE_NCURSES */

/* Enable X/Open Unix extensions */
#ifndef _XOPEN_SOURCE_EXTENDED
# define _XOPEN_SOURCE_EXTENDED
#endif

/* Define to `int' if <sys/types.h> does not define. */
/* #undef pid_t */

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */
