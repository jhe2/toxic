/*  conference.h
 *
 *
 *  Copyright (C) 2014 Toxic All Rights Reserved.
 *
 *  This file is part of Toxic.
 *
 *  Toxic is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Toxic is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Toxic.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef CONFERENCE_H
#define CONFERENCE_H

#include "toxic.h"
#include "windows.h"

#define SIDEBAR_WIDTH 16
#define SDBAR_OFST 2    /* Offset for the peer number box at the top of the statusbar */
#define MAX_CONFERENCE_NUM MAX_WINDOWS_NUM - 2
#define CONFERENCE_EVENT_WAIT 3

typedef struct ConferencePeer {
    bool       active;
    char       name[TOX_MAX_NAME_LENGTH];
    size_t     name_length;
    uint32_t   peernumber;
} ConferencePeer;

typedef struct {
    int chatwin;
    bool active;
    uint8_t type;
    int side_pos;    /* current position of the sidebar - used for scrolling up and down */
    time_t start_time;

    ConferencePeer *peer_list;
    uint32_t max_idx;

    char *name_list;
    uint32_t num_peers;

} ConferenceChat;

/* Frees all Toxic associated data structures for a conference (does not call tox_conference_delete() ) */
void free_conference(ToxWindow *self, uint32_t conferencenum);

int init_conference_win(Tox *m, uint32_t conferencenum, uint8_t type, const char *title, size_t title_length);

/* destroys and re-creates conference window with or without the peerlist */
void redraw_conference_win(ToxWindow *self);

#endif /* CONFERENCE_H */
