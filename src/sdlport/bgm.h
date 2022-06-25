/*
*  Abuse - dark 2D side-scrolling platform game
*  Copyright (c) 1995 Crack dot Com
*  Copyright (c) 2005-2011 Sam Hocevar <sam@hocevar.net>
*
*  This software was released into the Public Domain. As with most public
*  domain software, no warranty is made or implied by Crack dot Com, by
*  Jonathan Clark, or by Sam Hocevar.
*/


#ifndef bgm_h
#define bgm_h

class bgm {
public:
    virtual void play(unsigned char volume=127) {};
    virtual void stop(long fadeout_time=0) {};
    virtual int playing() = 0;
    void set_volume(int volume) {};
    virtual ~bgm() {}
};


#endif /* bgm_h */

