/*
    Автор библиотеки Alexandr Shamanin (@slpAkkie)

    Смотрите последнюю версию на GitHub - https://github.com/slpAkkie/c-lib
*/

#include <string.h>

#define STR_LEN 256

/**
    Находит первое вхождение подстроки
    Возвращает индекс первого совпавшего символа или -1 если подстрока не была найдена
*/
int strfind(char str[STR_LEN], char find[STR_LEN]);
// Заменяет подстроку на переданную
char *strrepl(char str[STR_LEN], char fnd[STR_LEN], char repl[STR_LEN]);
