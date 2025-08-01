/*****************************************************************************
 * x264_dllfuncs: Funcs for making x264 dll-compatible
 *****************************************************************************
 * Copyright (C) 2025 konakona08.
 * Original copyright: Copyright (C) 2003-2025 x264 project
 *
 * Original authors: Loren Merritt <lorenm@u.washington.edu>
 *                   Laurent Aimar <fenrir@via.ecp.fr>
 *                   Steven Walters <kemuri9@gmail.com>
 *                   Fiona Glaser <fiona@x264.com>
 *                   Kieran Kunhya <kieran@kunhya.com>
 *                   Henrik Gramner <henrik@gramner.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111, USA.
 *
 * This program is also available under a commercial proprietary license.
 * For more information, contact us at licensing@x264.com.
 *****************************************************************************/

#ifdef _WIN32
 /* The following two defines must be located before the inclusion of any system header files. */
#define WINVER       0x0500
#define _WIN32_WINNT 0x0500
#endif

#include "x264cli.h"

#ifdef _WIN32
#include <windows.h>
#include <io.h>       /* _setmode() */
#include <fcntl.h>    /* _O_BINARY */
#endif

#include <signal.h>
#include <getopt.h>
#include "input/input.h"
#include "output/output.h"
#include "filters/filters.h"


//ftello and fseeko are not defined in MSVC
long ftello(FILE* stream)
{
	return ftell(stream);
}
long fseeko(FILE* stream, long offset, int whence)
{
    return fseek(stream, offset, whence);
}

/* file i/o operation structs */
cli_input_t cli_input;
static cli_output_t cli_output;

static int cli_log_level = X264_LOG_DEBUG;
void x264_cli_log( const char *name, int i_level, const char *fmt, ... )
{
    if( i_level > cli_log_level )
        return;
    char *s_level;
    switch( i_level )
    {
        case X264_LOG_ERROR:
            s_level = "error";
            break;
        case X264_LOG_WARNING:
            s_level = "warning";
            break;
        case X264_LOG_INFO:
            s_level = "info";
            break;
        case X264_LOG_DEBUG:
            s_level = "debug";
            break;
        default:
            s_level = "unknown";
            break;
    }
    fprintf( stderr, "%s [%s]: ", name, s_level );
    va_list arg;
    va_start( arg, fmt );
    x264_vfprintf( stderr, fmt, arg );
    va_end( arg );
}

void x264_cli_printf( int i_level, const char *fmt, ... )
{
    if( i_level > cli_log_level )
        return;
    va_list arg;
    va_start( arg, fmt );
    x264_vfprintf( stderr, fmt, arg );
    va_end( arg );
}