#include "header.h"
#include "../strings.h"

int capicua(char *string)
{
    int length = 0;
    int i, j, isPalindrome = 1;

    while(string[length] != STRING_NULL) length++;

    for(i = 0, j = length - 1; i < length/2 ; i++, j--)
    {
        if(string[i] != string[j])
        {
            isPalindrome = 0;
            break;
        }
    }

    return isPalindrome;
}
