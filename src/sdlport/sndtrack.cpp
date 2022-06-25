/*
*  Abuse - dark 2D side-scrolling platform game
*  Copyright (c) 2001 Anthony Kruize <trandor@labyrinth.net.au>
*  Copyright (c) 2005-2011 Sam Hocevar <sam@hocevar.net>
*
*  This program is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 2 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program; if not, write to the Free Software Foundation,
*  Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
*/


#include "specs.h"
#include "sndtrack.h"
#include "sound.h"
#include "wavesong.hpp"

soundtrack::soundtrack(uint8_t soundsystemState) {
        
}

soundtrack::~soundtrack() {
    
}

char* hmiMusicFileSearch(char* n, char* result) {
    // what to do with the hardcoded extension in path?
    sprintf(result,"music/abuse%c%c.hmi",n[12],n[13]);
    return result;
}


char* redbookMusicFileSearch(char* n, char* result) {
    sprintf(result,"music/cd/track%c%c.wav",n[12],n[13]);
    return result;
}

char* musicSearchStrategy(char* n, char* result) {
    // todo: add fallback logic here
    // and handle the case, where redbook audio is explictly disabled
    return redbookMusicFileSearch(n, result);
}

bgm* songFactoryMethod(char* nm) {
    return new waveSong(nm);
}


void soundtrack::play_level_bgm(char *n, bgm **current_song_ptr, int music_volume) {
    if (strstr(n,"levels/level"))
    {
        char nm[100];
        musicSearchStrategy(n, nm);
        bFILE *fp=open_file(nm,"rb");
        if (fp->open_failure())
        {
            delete fp;
        }
        else
        {
            bgm* current_song = *current_song_ptr;
            if (current_song) { current_song->stop(); delete current_song; }
            
            delete fp;
            bgm* new_song = songFactoryMethod(nm);
            new_song->play(music_volume);
            *current_song_ptr = new_song;
        }
    }
}


