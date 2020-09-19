#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

typedef char* string;

#define startRedColor printf("\033[31m")
#define startBlueColor printf("\033[34m")
#define startGreenColor printf("\033[32m")
#define endColor printf("\033[30m")

#ifdef __SLP_DEV_MODE__
#define redInput(_format, _offer, _dist) \
    startRedColor; \
    printf( _offer ); \
    scanf_s(_format, &_dist); \
    endColor
#define blueInput(_format, _offer, _dist) \
    startBlueColor; \
    printf( _offer ); \
    scanf_s(_format, &_dist); \
    endColor
#define greenInput(_format, _offer, _dist) \
    startGreenColor; \
    printf( _offer ); \
    scanf_s(_format, &_dist); \
    endColor
#endif // !SLP_FULL_MODE

#define nl printf("\n")
#define cls system("cls")
#define pause system("pause")
#define pause_u system("pause > nul")
#define _STD_READ_BUFFER 255

void redPrint( const string format, ... );
void bluePrint( const string format, ... );
void greenPrint( const string format, ... );

bool getCorrectInt( int* dist );
bool getCorrectFloat( float* dist );