/*
    Автор библиотеки Alexandr Shamanin (@slpAkkie)

    Смотрите последнюю версию на GitHub - https://github.com/slpAkkie/c-lib
*/

#pragma once
#include "slp_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Размер команды "title "
#define _TITLE_COMMAND_LEN 6
// Максимальная длинна полной комманды "title ..."
#define _MAX_TITLE_COMMAND_LEN 64

// Инициализировать настройки консоли (Необходимо для использование цветного вывода)
void init(const string title);
/*
    Задать пользователю вопрос с вариантами Да (Y) и Нет (N)
    Вернет true если пользователь ответил да и false в остальных случаях
*/
bool askUserYN(const string question);
