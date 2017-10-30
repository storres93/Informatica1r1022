#include "../strings.h"
#include "header.h"

void decBin(int decimal, char *binario)
{
    int i;
    for(i = 0; i < STRING_MAX_LENGTH; i++)
    {
        binario[i] = '0';
    }

    i--;

    binario[i] = STRING_NULL;

    i--;

    while(decimal > 0)
    {
        binario[i] = '0' + (decimal % 2);
        i--;
        decimal /= 2;
    }
}
