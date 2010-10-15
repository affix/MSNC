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
#include <stdlib.h>
#include <errno.h>

#define END       666

#define INIT_MENU_ITEM(text, action, flags)  \
{                                            \
  (unsigned char *) (text),                  \
  (action),                                  \
  (flags),                                   \
}

#define END_ITEM \
{                \
  NULL,          \
  cmd_none,      \
  END,           \
}

static struct menu_item file_menu[] = {
    INIT_MENU_ITEM("File", cmd_none, 0),
    INIT_MENU_ITEM("Manual", cmd_manual, 0),
    INIT_MENU_ITEM("Console", cmd_console, 0),
    INIT_MENU_ITEM("Quit", cmd_quit, 0),
    END_ITEM,
};

static struct menu_item action_menu[] = {
    INIT_MENU_ITEM("Actions", cmd_none, 0),
    INIT_MENU_ITEM("Change nick", cmd_changenick, 0),
    INIT_MENU_ITEM("Set personal message", cmd_setpsm, 0),
    INIT_MENU_ITEM("Invite principal", cmd_invite, 0),
    INIT_MENU_ITEM("Set talkfilter", cmd_setfilter, 0),
    INIT_MENU_ITEM("Redraw interface", cmd_redraw, 0),
    END_ITEM,
};

static struct menu_item contact_menu[] = {
    INIT_MENU_ITEM("Contacts", cmd_none, 0),
    INIT_MENU_ITEM("Add", cmd_addcontact, 0),
    INIT_MENU_ITEM("Remove", cmd_removecontact, 0),
    INIT_MENU_ITEM("Block", cmd_blockcontact, 0),
    INIT_MENU_ITEM("Un-block", cmd_unblockcontact, 0),
    INIT_MENU_ITEM("Set custom nick", cmd_setcustomnick, 0),
    INIT_MENU_ITEM("Un-set custom nick", cmd_unsetcustomnick, 0),
    END_ITEM,
};

static struct menu_item status_menu[] = {
    INIT_MENU_ITEM("Status", cmd_none, 0),
    INIT_MENU_ITEM("Online", cmd_statusonline, 0),
    INIT_MENU_ITEM("Away", cmd_statusaway, 0),
    INIT_MENU_ITEM("Idle", cmd_statusidle, 0),
    INIT_MENU_ITEM("Be right back", cmd_statusbrb, 0),
    INIT_MENU_ITEM("Busy", cmd_statusbusy, 0),
    INIT_MENU_ITEM("On phone", cmd_statusphone, 0),
    INIT_MENU_ITEM("On lunch", cmd_statuslunch, 0),
    INIT_MENU_ITEM("Hidden", cmd_statushidden, 0),
    END_ITEM,
};
