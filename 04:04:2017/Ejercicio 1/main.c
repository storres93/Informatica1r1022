#include "header.h"

int main(void)
{
	int numeros[TAMANO_VECTOR], i;
	for(i = 0; i < TAMANO_VECTOR; i++)
	{
		printf("Ingrese el elemento %d\n", (i + 1));
		scanf("%d", &numeros[i]);
	}

	for(i = 0; i < TAMANO_VECTOR; i++)
	{
		printf("El elemento %d equivale a %d\n", (i + 1), numeros[i]);
	}
}