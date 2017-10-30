#include <stdio.h>
#include "header.h"
#include "../strings.h"

int main(void)
{
    char binario[STRING_MAX_LENGTH];
    char hexa[STRING_MAX_LENGTH];
    printf("Por favor ingrese el numero en binario que desea convertir\n");
    scanf("%s", binario);
    switch(binHex(binario, hexa))
    {
        case 0:
            printf("Su numero en hexa es: %s\n", hexa);
           break;
        case -1:
            printf("Ingrese un numero binario que tenga 32 bits en total\n");
            break;
        case -2:
            printf("Ingrese un numero binario valido");
            break;
    }
    return 0;
}
