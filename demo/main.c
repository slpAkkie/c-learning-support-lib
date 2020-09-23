#include "slp_io.h"
#include "slp_crumbs.h"
#include "slp_arrays.h"
#include "slp_matr.h"


void main( void ) {
    // Вызываем инициализацию настроек консоли и передаем название окна
    init( "Тестирование заголовочных файлов" );

    while ( true ) {
        bluePrint( "Вы запустили проект разработки slpLib_c\n\n" );

        if ( !askUserYN( "Хотите пройтись по возможностям библиотеки?" ) ) break;
        cls;

        // Здесь будем хранить ошибки ввода
        bool inputError;
        printf( "Для начала покажу вам защиту на ввод некорректных данных\n" );

        greenPrint( "\nСначала защита для ввода целых чисел:\n" );
        printf( "Введите x >> " );
        // Так можно реализовать обработку неправильного ввода
        int x;
        inputError = getCorrectInt( &x );
        if ( !inputError ) redPrint( "Вы ввели не целое число и сработала защита\n" );
        else greenPrint( "Вы правильно ввели целое число x = %d\n", x );

        greenPrint( "\nТеперь защита для вещественных чисел:\n" );
        printf( "Введите y >> " );
        // Теперь обработать ошибку ввода вещественных
        float y;
        inputError = getCorrectFloat( &y );
        if ( !inputError ) redPrint( "Вы ввели не целое число и сработала защита\n" );
        else greenPrint( "Вы правильно ввели вещественное число y = %.2f\n", y );

        if ( !askUserYN( "\n\nПродолжить просмотр?" ) ) break;
        cls;

        bluePrint( "Теперь покажу вам базовую работу с массивами\n\n" );
        char arrAlias = 'X';
        // Получаем размер массива в переменную типа vsize
        vsize arrLen = getArrLen( arrAlias, false );
        // Массив создается как обычная переменная типа farr (Если вещественный и iarr если целочисленный)
        farr arrX;
        // Но ему необходимо задать этим макросом размер
        setArrLenght( arrX, farr, arrLen );
        cls;

        bluePrint( "Теперь давайте введем сам массив:\n" );
        fillFloatArray( arrX, arrAlias, arrLen );
        cls;

        printFloatArray( arrX, arrAlias, arrLen, "Ваш введенный" );

        pause;
        cls;
        bluePrint( "Как на счет взглянуть на работу с матрицами?\n" );
        char matrAlias = 'M';
        // Получаем размер матрицы в переменную типа msize
        msize matr_size = getMatrSize( matrAlias, false );
        // С матрицей так же, описывается как переменная с указанием типа imatr (Если вещественная и imatr если целочисленная)
        imatr matrX;
        // Но ей необходимо задать этим макросом размер
        setMatrLenght( matrX, imatr, imatr_el, matr_size );
        fillIntMatr( matr_size, matrX, matrAlias );
        printIntMatr( matr_size, matrX, matrAlias, "Ваша введенная" );

        pause;
        cls;
        bluePrint( "Вот такой функционал есть у моей библиотеке пока что :)\n" );

        if ( !askUserYN( "\n\nХотите начать заново?" ) ) break;
    }
}