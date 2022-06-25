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

#ifdef WIN32
# include <Windows.h>
#endif
#include <cstring>

#include "dsubdir.hpp"
#include "specs.h"

bool data_sub_dir_exists(char *dir) {
    char *sfxdir, *datadir;
    bool result = true;
    datadir = get_filename_prefix();
    sfxdir = (char *)malloc( strlen( datadir ) + 5 + 1 ); // todo: what the hell those lengh additions mean?
    sprintf( sfxdir, "%s%s", datadir, dir );
#ifdef WIN32
    // Attempting to fopen a directory under Windows will fail, and
    // opendir does not exist. Use GetFileAttributes instead.
    if( GetFileAttributes( sfxdir ) == INVALID_FILE_ATTRIBUTES )
#else
        FILE *fd = NULL;
    if( (fd = fopen( sfxdir,"r" )) == NULL )
#endif
    {
        // Didn't find the directory, so disable sound.
        printf( "Sound: Couldn't find the media directory %s)\n", sfxdir );
        result = false;
    }
    free( sfxdir );
    return result;
}
