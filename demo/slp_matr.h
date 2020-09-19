#pragma once
#include "slp_io.h"
#include <stdio.h>

#define MIN_MATR_SIZE 1
#define MAX_MATR_SIZE 5

typedef int** imatr;
typedef int imatr_el;

#ifndef _VSIZE_T
    #define _VSIZE_T
    typedef unsigned int vsize;
#endif // !_VSIZE_T

typedef struct matr_size {
    vsize rows, cols;
} msize;

#define setMatrLenght(matr, mType, eType, size) \
    matr = ( mType )malloc( size.rows * sizeof( eType ) ); \
    for (int i = 0; i < size.rows; i++) matr[i] = (eType*)malloc( size.cols * sizeof( eType ) )

msize getMatrSize( const char symbol, bool clsMode );
void fillIntMatr( msize size, imatr matr, char symbol );
void printIntMatr( msize size, imatr matr, char symbol, string status );