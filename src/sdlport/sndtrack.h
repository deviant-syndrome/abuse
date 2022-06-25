/*
*  Abuse - dark 2D side-scrolling platform game
*  Copyright (c) 1995 Crack dot Com
*  Copyright (c) 2005-2011 Sam Hocevar <sam@hocevar.net>
*
*  This software was released into the Public Domain. As with most public
*  domain software, no warranty is made or implied by Crack dot Com, by
*  Jonathan Clark, or by Sam Hocevar.
*/

#ifndef sndtrack_h
#define sndtrack_h

#include "bgm.h"

// bgmFactory
// default logic:
// 1. If music is disabled -> skip
// 2. If redbook is disabled
//      2a. try to find HMI file
//      2b. if exists, create song
//      2c. if not -> throw error
// 3.If redbook is enabled
//    3a. try to find WAV
//    3b. fallback: try to find HMI
//    3c. if nothing found - fail
class soundtrack {
    public:
    soundtrack(uint8_t soundsystemState);
    ~soundtrack();
    
    void play_level_bgm(char *level_name, bgm **current_song, int music_volume);
};

#endif /* sndtrack_h */


