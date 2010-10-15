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

#include "sig.h"
#include "common.h"

int has_received_sigwinch = 0;
int has_received_sighup = 0;
int has_received_sigint = 0;

void
sighup(int sig)
{
    has_received_sighup = 1;
}

void
sigint(int sig)
{
    if (has_received_sigint)
        UI_err_exit("Forced quit, settings not saved\n");

    if (UI_dialog_getch("Are you sure you want to quit? (y/n)") == 'y')
        has_received_sigint = 1;
}

void
sigwinch(int sig)
{
    has_received_sigwinch = 1;
}

void
UI_manual_resize()
{
    sigwinch(0);
}

int
UI_is_resized()
{
    int i = has_received_sigwinch;

    has_received_sigwinch = 0;
    return i;
}

int
UI_is_killed()
{
    int i;

    i = (has_received_sighup || has_received_sigint);
    has_received_sighup = 0;
    has_received_sigint = 0;
    return i;
}

void
UI_setup_signals()
{
    signal(SIGHUP, sighup);
    signal(SIGINT, sigint);
    signal(SIGWINCH, sigwinch);
}
