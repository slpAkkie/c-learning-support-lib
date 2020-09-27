/*
    Автор библиотеки slpAkkie (GitHub Alexandr Shamanin)

    Смотрите последнюю версию на GitHub - https://github.com/slpAkkie/slpCLib
*/

#include "slp_io.h"

bool getCorrectInt( int* dist ) {
    string input = ( string ) malloc( _STD_READ_BUFFER * sizeof( char ) );
    gets_s( input, _STD_READ_BUFFER );

    int startFrom = ( input[0] == '-' ) ? 1 : 0;
    if ( input[startFrom] == '\0' ) return false;

    for ( int i = startFrom; input[i] != '\0'; i++ ) if ( input[i] < '0' || input[i] > '9' ) return false;
    *dist = atoi( input );

    return true;
}

bool getCorrectFloat( float* dist ) {
    string input = ( string ) malloc( _STD_READ_BUFFER * sizeof( char ) );
    gets_s( input, _STD_READ_BUFFER );

    int dots = 0, startFrom = 0;
    ( input[0] == '-' ) && startFrom++;
    if ( input[startFrom] == '.' || input[startFrom] == '\0' ) return false;

    for ( int i = startFrom; input[i] != '\0'; i++ ) {
        if ( input[i] == ',' ) input[i] = '.';
        if ( input[i] == '.' ) dots++;
        if ( ( input[i] < '0' || input[i] > '9' ) && input[i] != '.' || dots > 1 ) return false;
    }
    *dist = ( float ) atof( input );

    return true;
}

void redPrint( const string format, ... ) {
    startRedColor;

    va_list args;
    va_start( args, format );
    vprintf( format, args );
    va_end( args );

    endColor;
}

void bluePrint( const string format, ... ) {
    startBlueColor;

    va_list args;
    va_start( args, format );
    vprintf( format, args );
    va_end( args );

    endColor;
}

void greenPrint( const string format, ... ) {
    startGreenColor;

    va_list args;
    va_start( args, format );
    vprintf( format, args );
    va_end( args );

    endColor;
}
