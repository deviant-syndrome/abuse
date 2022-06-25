//
//  wavesong.hpp
//  sdlport
//
//  Created by Andrei Katkov on 25.6.2022.
//

#ifndef wavesong_hpp
#define wavesong_hpp

#include "bgm.h"
#include "SDL_mixer.h"


class waveSong : public bgm {
public:
    waveSong(char const *filename);
    void play(unsigned char volume);
    void stop(long fadeout_time);
    int playing();
    void set_volume(int volume);
    ~waveSong();
private:
#if !defined __CELLOS_LV2__
    char *Name;
    unsigned char *data;
    unsigned long song_id;
    Mix_Chunk* music;
    SDL_RWops* rw;
    int channel;
#endif
};

#endif /* wavesong_hpp */
