#pragma once
#include "slp_io.h"
#include <stdio.h>

// ћинимальный размер матрицы по одной из координат
#define MIN_MATR_SIZE 1
// ћаксимальный размер матрицы по одной из координат
#define MAX_MATR_SIZE 5

// ÷елочисленна€ матрицы
typedef int** imatr;
// Ёлемент целочисленной матрицы
typedef int imatr_el;

// ¬ещественна€ матрицы
typedef float** fmatr;
// Ёлемент вещественной матрицы
typedef float fmatr_el;

#ifndef _VSIZE_T
    #define _VSIZE_T
    // –азмер массива
    typedef unsigned int vsize;
#endif // !_VSIZE_T

// –азмер матрицы
typedef struct matr_size {
    vsize rows, cols;
} msize;

// ”станавливает размер матрицы
#define setMatrLenght(matr, mType, eType, size) \
    matr = ( mType )malloc( size.rows * sizeof( eType ) ); \
    for (int i = 0; i < size.rows; i++) matr[i] = (eType*)malloc( size.cols * sizeof( eType ) )

/*
    ѕолучает от пользовател€ размер матрицы
    ¬озвращает размер матрицы структурой msize
*/
msize getMatrSize( const char symbol, bool clsMode );
// «аполн€ет целочисленную матрицу
void fillIntMatr( msize size, imatr matr, char symbol );
// ¬ыводит целочисленную матрицу
void printIntMatr( msize size, imatr matr, char symbol, string status );
// «аполн€ет вещественную матрицу
void fillFloatMatr( msize size, fmatr matr, char symbol );
// ¬ыводит вещественную матрицу
void printFloatMatr( msize size, fmatr matr, char symbol, string status );