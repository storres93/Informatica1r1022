#include <stdio.h>
#include "../strings.h"
#include "header.h"

int main(void)
{
    char string[STRING_MAX_LENGTH];
    int isPalindrome;

    printf("Ingrese el string que quiera chequear que sea capicua\n");
    scanf("%s", string);

    isPalindrome = capicua(string);

    if(isPalindrome)
    {
        printf("El string %s es capicua\n", string);
    } else {
        printf("El string %s no es capicua\n", string);
    }
    return 0;
}
