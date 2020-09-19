#include "slp_io.h"
#include "slp_crumbs.h"
#include "slp_arrays.h"
#include "slp_matr.h"


void main( void ) {
    init( "Тестирование заголовочных файлов" );

    while ( true ) {
        bluePrint( "Вы запустили проект разработки slpLib_c\n\n" );

        if ( !askUserYN( "Хотите пройтись по возможностям библиотеки?" ) ) break;
        cls;

        bool inputError;
        printf( "Для начала покажу вам защиту на ввод некорректных данных\n" );

        greenPrint( "\nСначала защита для ввода целых чисел:\n" );
        printf( "Введите x >> " );
        int x;
        inputError = getCorrectInt( &x );
        if ( !inputError ) redPrint( "Вы ввели не целое число и сработала защита\n" );
        else greenPrint( "Вы правильно ввели целое число x = %d\n", x );

        greenPrint( "\nТеперь защита для вещественных чисел:\n" );
        printf( "Введите y >> " );
        float y;
        inputError = getCorrectFloat( &y );
        if ( !inputError ) redPrint( "Вы ввели не целое число и сработала защита\n" );
        else greenPrint( "Вы правильно ввели вещественное число y = %.2f\n", y );

        if ( !askUserYN( "\n\nПродолжить просмотр?" ) ) break;
        cls;

        bluePrint( "Теперь покажу вам базовую работу с массивами\n\n" );
        char arrAlias = 'X';
        vsize arrLen = getArrLen( arrAlias, false );
        iarr arrX;
        setArrLenght( arrX, iarr, arrLen );
        cls;

        bluePrint( "Теперь давайте введем сам массив:\n" );
        fillIntArray( arrX, arrAlias, arrLen );
        cls;

        printIntArray( arrX, arrAlias, arrLen, "Ваш введенный" );

        pause;
        cls;
        bluePrint( "Как на счет взглянуть на работу с матрицами?\n" );
        char matrAlias = 'M';
        msize matr_size = getMatrSize( matrAlias, false );
        imatr matrX;
        setMatrLenght( matrX, imatr, imatr_el, matr_size );
        fillIntMatr( matr_size, matrX, matrAlias );
        printIntMatr( matr_size, matrX, matrAlias, "Ваша введенная" );

        pause;
        cls;
        bluePrint( "Вот такой функционал есть у моей библиотеке пока что :)\n" );

        if ( !askUserYN( "\n\nХотите начать заново?" ) ) break;
    }
}