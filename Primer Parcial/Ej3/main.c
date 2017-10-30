#include <stdio.h>
#include "../strings.h"
#include "header.h"

int main(void)
{
    char string[STRING_MAX_LENGTH];
    char characterToChange, characterToFind;
    int replaces;

    printf("Ingrese el string que quiera modificar\n");
    scanf("%s", string);
    printf("Ingrese el caracter que quiere replazar\n");
    scanf("\n%c", &characterToFind);
    printf("Ingrese el caracter por el cual quiere que se reemplaze\n");
    scanf("\n%c", &characterToChange);

    replaces = searchAndReplace(string, characterToFind, characterToChange);

    printf("El nuevo string es: %s\nEl caracter '%c' se reemplazo por '%c' %d veces\n", string, characterToFind, characterToChange, replaces);

    return 0;
}
