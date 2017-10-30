#include "../strings.h"
#include "header.h"
#include <stdio.h>
int binHex(char *binario, char *hexa)
{
    int i, j, k;
    int sum_aux;
    if(string_length(binario) != 32)
    {
        return -1;
    }
    if(!validBinary(binario))
    {
        return -2;
    }

    for(i = 0, k = 0; i < STRING_MAX_LENGTH - 1; i += 4, k++)
    {
        sum_aux = 0;
        for(j = 0; j < 4; j++)
        {
            if(binario[i + j] == '1')
            {
                sum_aux += _pow(2, 3 - j);
            }
        }

        if(sum_aux > 9)
        {
            hexa[k] = 'A' + (sum_aux - 10);
        } else {
            hexa[k] = '0' + sum_aux;
        }
    }

    hexa[k] = STRING_NULL;

    return 0;
}

int string_length(char *string)
{
    int i = 0;
    while(string[i] != STRING_NULL)
    {
        i++;
    }

    return i;
}

int validBinary(char *binary)
{
    int i = 0;
    int valid = 1;
    while(binary[i] != STRING_NULL)
    {
        if(binary[i] != '1' && binary[i] != '0')
        {
            valid = 0;
            break;
        }

        i++;
    }

    return valid;
}

int _pow(int base, int power)
{
    if(power == 0)
    {
        return 1;
    } else {
        return base * _pow(base, power - 1);
    }
}
