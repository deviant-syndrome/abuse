/*
 *  Abuse - dark 2D side-scrolling platform game
 *  Copyright (c) 1995 Crack dot Com
 *  Copyright (c) 2005-2011 Sam Hocevar <sam@hocevar.net>
 *
 *  This software was released into the Public Domain. As with most public
 *  domain software, no warranty is made or implied by Crack dot Com, by
 *  Jonathan Clark, or by Sam Hocevar.
 */

#ifndef __SOUND_H__
#define __SOUND_H__

#if !defined __CELLOS_LV2__
#   include "SDL_mixer.h"
#endif

#include "bgm.h"
#define ENABLE_MUSIC 1
#define ENABLE_SFX   1

bool sfx_enabled(uint8_t sound_system_state);
bool music_enabled(uint8_t sound_system_state);

uint8_t sound_init(int argc, char **argv);
void sound_uninit();
void print_sound_options(); // print the options avaible for sound

class sound_effect
{
public:
    sound_effect(char const *filename);
    ~sound_effect();

    void play(int volume = 127, int pitch = 128, int panpot = 128);

private:
#if !defined __CELLOS_LV2__
    Mix_Chunk* m_chunk;
#endif
};

class song : public bgm
{
public:
#if !defined __CELLOS_LV2__
    char const *name() { return Name; }
#endif
    song(char const *filename);
    void play(unsigned char volume=127);
    void stop(long fadeout_time=0); // time in ms
    int playing();
    void set_volume(int volume);
    ~song();

private:
#if !defined __CELLOS_LV2__
    char *Name;
    unsigned char *data;
    unsigned long song_id;
    Mix_Music* music;
    SDL_RWops* rw;
#endif
};

void start_level_bgm(char *level_name, bgm **current_song, int music_volume);

#endif

