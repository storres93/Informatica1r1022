#include "header.h"
#include "../strings.h"

int searchAndReplace(char *string, char caracter, char change)
{
    int i = 0;
    int replaces = 0;
    while(string[i] != STRING_NULL)
    {
        if(string[i] == caracter)
        {
            string[i] = change;
            replaces++;
        }

        i++;
    }

    return replaces;
}
