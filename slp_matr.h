/*
    Автор библиотеки slpAkkie (GitHub Alexandr Shamanin)

    Смотрите последнюю версию на GitHub - https://github.com/slpAkkie/slpCLib
*/

#pragma once
#include "slp_io.h"
#include <stdio.h>

// Минимальный размер матрицы по одной из координат
#define MIN_MATR_SIZE 1
// Максимальный размер матрицы по одной из координат
#define MAX_MATR_SIZE 5

// Целочисленная матрицы
typedef int** imatr;
// Элемент целочисленной матрицы
typedef int imatr_el;

// Вещественная матрицы
typedef float** fmatr;
// Элемент вещественной матрицы
typedef float fmatr_el;

#ifndef _VSIZE_T
#define _VSIZE_T
// Размер массива
typedef unsigned int vsize;
#endif // !_VSIZE_T

// Размер матрицы
typedef struct matr_size {
    vsize rows, cols;
} msize;

// Устанавливает размер матрицы
#define setMatrLenght(matr, mType, eType, size) \
    matr = ( mType )malloc( size.rows * sizeof( eType ) ); \
    for (int i = 0; i < size.rows; i++) matr[i] = (eType*)malloc( size.cols * sizeof( eType ) )

/*
    Получает от пользователя размер матрицы
    Возвращает размер матрицы структурой msize
*/
msize getMatrSize( const string symbol, bool clsMode );
// Заполняет целочисленную матрицу
void fillIntMatr( msize size, imatr matr, string symbol );
// Выводит целочисленную матрицу
void printIntMatr( msize size, imatr matr, string symbol, string status );
// Заполняет вещественную матрицу
void fillFloatMatr( msize size, fmatr matr, string symbol );
// Выводит вещественную матрицу
void printFloatMatr( msize size, fmatr matr, string symbol, string status );
