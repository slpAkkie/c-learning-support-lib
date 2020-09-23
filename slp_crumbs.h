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
void init( const string title );
bool askUserYN( const string question );