/*
    јвтор библиотеки slpAkkie (GitHub Alexandr Shamanin)

    —мотрите последнюю версию на GitHub - https://github.com/slpAkkie/c-lib
*/

#include "slp_crumbs.h"

void init(const string title)
{
    const rsize_t titleLen = strlen(title);
    char titleCommand[_MAX_TITLE_COMMAND_LEN] = "title ";

    if (titleLen > 0 && titleLen < _MAX_TITLE_COMMAND_LEN - _TITLE_COMMAND_LEN)
        strcat_s(titleCommand, sizeof titleCommand, title);
    else
        strcat_s(titleCommand, sizeof titleCommand, __TIMESTAMP__);

    system("chcp 65001 > nul");
    system("color f0");
    system(titleCommand);
}

bool askUserYN(const string question)
{
    char answer[_STD_READ_BUFFER];

    printf("%s (y | N)\n", question);
    startGreenColor;
    printf(">> ");
    gets_s(answer, _STD_READ_BUFFER);
    endColor;
    cls;

    if (strlen(answer) != 1)
        return false;

    return answer[0] == 'y';
}
