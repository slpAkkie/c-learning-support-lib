/*
    Автор библиотеки slpAkkie (GitHub Alexandr Shamanin)

    Смотрите последнюю версию на GitHub - https://github.com/slpAkkie/slpCLib
*/

#pragma once
#include "slp_io.h"
#include <stdio.h>

// Минимальный размер массива
#define _MIN_ARR_LEN 2
// Максимальный размер массива
#define _MAX_ARR_LEN 50

// Целочисленный массив
typedef int* iarr;

// Вещественный массив
typedef float* farr;

#ifndef _VSIZE_T
    #define _VSIZE_T
    // Размер массива
    typedef unsigned int vsize;
#endif // !_VSIZE_T

// Устанавливает размер массива
#define setArrLenght(arr, type, lenght) arr = ( type )malloc( lenght * sizeof( type ) )

/*
    Получает от пользователя размер массива
    Возвращает размер массива типа vsize (Фактический тип: int)
*/
vsize getArrLen( const char symbol, bool clsMode );
// Заполняет целочисленный массив
void fillIntArray( iarr arr, const char symbol, vsize len );
// Выводит целочисленный массив
void printIntArray( iarr arr, const char symbol, vsize len, string status );
// Заполняет вещественный массив
void fillFloatArray( farr arr, const char symbol, vsize len );
// Выводит вещественный массив
void printFloatArray( farr arr, const char symbol, vsize len, string status );
