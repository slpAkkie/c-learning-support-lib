/*
    Автор библиотеки Alexandr Shamanin (@slpAkkie)

    Смотрите последнюю версию на GitHub - https://github.com/slpAkkie/c-lib
*/

#include <slp_strf.h>

int strfind(char str[STR_LEN], char find[STR_LEN])
{
    int first = -1;
    int findLen = strlen(find) - 1;

    for (int i = 0, c = 0; i < STR_LEN; i++)
    {
        if (str[i] == find[c])
        {
            c++;
            if (first == -1)
                first = i;
        }
        else
        {
            c = 0;
            first = -1;
        }

        if (c > findLen)
            break;
    }

    return first;
}

char *strrepl(char str[STR_LEN], char fnd[STR_LEN], char repl[STR_LEN])
{
    int start = strfind(str, fnd);

    while (start != -1)
    {
        int lenDiff = strlen(repl) - strlen(fnd);
        int direction = 1;

        if (lenDiff < 0)
            direction = -1;

        for (int j = 0; j < (lenDiff * direction); j++)
        {
            if (direction < 0)
                for (int i = start; i <= strlen(str); i++)
                    str[i] = str[i + 1];
            else
                for (int i = strlen(str); i >= start; i--)
                    str[i + 1] = str[i];
        }

        for (int i = start, c = 0; i < start + strlen(repl); i++, c++)
            str[i] = repl[c];

        start = find(str, fnd);
    }

    return str;
}
