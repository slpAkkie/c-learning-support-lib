/*
    Автор библиотеки slpAkkie (GitHub Alexandr Shamanin)

    Смотрите последнюю версию на GitHub - https://github.com/slpAkkie/slpCLib
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

#define _SLP_IO

// Строка (Фактически указатель на массив символов)
typedef char* string;

/*
* Макросы для управления цветом отображения текста в консоли
* Используйте только если использовали функцию init. В стандартных цветах консоли эти макросы будут вести себя некорректно
*/

// Писать дальше красным цветом (Только с использованным init())
#define startRedColor printf("\033[31m")
// Писать дальше синим цветом (Только с использованным init())
#define startBlueColor printf("\033[34m")
// Писать дальше зеленым цветом (Только с использованным init())
#define startGreenColor printf("\033[32m")
// Писать цветом по умолчанию (Только с использованным init())
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

// Поставить перенос на новую строку
#define nl printf("\n")
// Очистить экран
#define cls system("cls")
// Поставить исполнение программы на паузу
#define pause system("pause")
// Поставить исполнение программы на паузу без сообщения
#define pause_s system("pause > nul")
#define _STD_READ_BUFFER 255

// Как printf только красным цветом (Только с использованным init())
void redPrint( const string format, ... );
// Как printf только синим цветом (Только с использованным init())
void bluePrint( const string format, ... );
// Как printf только зеленым цветом (Только с использованным init())
void greenPrint( const string format, ... );

/*
    Безопасный ввод целого числа
    Возвращает true, если запись удалась и false в противном случае
*/
bool getCorrectInt( int* dist );
/*
    Безопасный ввод вещественного числа
    Возвращает true, если запись удалась и false в противном случае
*/
bool getCorrectFloat( float* dist );
