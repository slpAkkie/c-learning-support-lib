#pragma once
#include "slp_io.h"
#include <stdio.h>

typedef int* iarr;

#ifndef _VSIZE_T
    #define _VSIZE_T
    typedef unsigned int vsize;
#endif // !_VSIZE_T

#define setArrLenght(arr, type, lenght) arr = ( type )malloc( lenght * sizeof( type ) )

#define _MAX_ARR_LEN 50
#define _MIN_ARR_LEN 2

int getArrLen( const char symbol, bool clsMode );
void fillIntArray( iarr arr, const char symbol, vsize len );
void printIntArray( iarr arr, const char symbol, vsize len, string status );