//
//  wavesong.cpp
//  sdlport
//
//  Created by Andrei Katkov on 25.6.2022.
//

#include "wavesong.hpp"
#include "specs.h"

waveSong::waveSong(char const *filename) {
    data = NULL;
    Name = strdup(filename);
    song_id = 0;
    channel = 0;
        
    rw = NULL;
    music = NULL;
    
    char realname[255];
    strcpy(realname, get_filename_prefix());
    strcat(realname, filename);
    
    music = Mix_LoadWAV(realname);
    
    if(music == NULL) {
        fprintf(stderr, "Unable to load WAV file: %s\n", Mix_GetError());
    }
}

void waveSong::play(unsigned char volume) {
    // stub
    song_id = 1;
    channel = Mix_PlayChannel(-1, music, 0);
    if(channel == -1) {
        fprintf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
    }
    Mix_Volume(channel, volume);
}

void waveSong::stop(long fadeout_time) {
    song_id = 0;
    Mix_FadeOutChannel(channel, 100);
}

int waveSong::playing() {
  return Mix_Playing(channel);
}

void waveSong::set_volume(int volume) {
    Mix_Volume(channel, volume);
}

waveSong::~waveSong() {
    Mix_FreeChunk(music);
}
