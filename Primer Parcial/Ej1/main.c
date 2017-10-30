#include <stdio.h>
#include "header.h"
#include "../strings.h"

int main(void)
{
    char binario[STRING_MAX_LENGTH];
    int decimal;
    printf("Por favor ingrese el numero en decimal que desea convertir\n");
    scanf("%d", &decimal);
    decBin(decimal, binario);
    printf("Su numero en binario es: %s\n", binario);
    return 0;
}
