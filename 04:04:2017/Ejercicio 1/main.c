#include "header.h"

int main(void)
{
	int numeros[TAMANO_VECTOR], i;

	cargarVectorDeInt(numeros, TAMANO_VECTOR);

	for(i = 0; i < TAMANO_VECTOR; i++)
	{
		printf("El elemento %d equivale a %d\n", (i + 1), numeros[i]);
	}

	return 0;
}

void cargarVectorDeInt(int vector[], int tamano)
{
	int i;

	for(i = 0; i < TAMANO_VECTOR; i++)
	{
		printf("Ingrese el elemento %d\n", (i + 1));
		scanf("%d", &vector[i]);
	}
}