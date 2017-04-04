#include "header.h"

int main(void)
{
	int numeros[TAMANO_VECTOR], menor, mayor;

	cargarVectorDeInt(numeros, TAMANO_VECTOR);

	menor = encontrarMenor(numeros, TAMANO_VECTOR);

	mayor = encontrarMenor(numeros, TAMANO_VECTOR);

	printf("El menor numero es %d\n", menor);

	printf("El mayor numero es %d\n", mayor);

	//alternativamente

	bubbleSortAscendente(vector, TAMANO_VECTOR);

	printf("El menor numero es %d\n", vector[0]);

	printf("El mayor numero es %d\n", vector[TAMANO_VECTOR - 1]);

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

int encontrarMenor(int vector[], tamano)
{
	int i, j, menor = vector[0];

	for(i = 0; i < TAMANO_VECTOR; i++)
	{
		if(vector[i] < menor)
			menor = vector[i];
	}

	return menor;
}

int encontrarMayor(int vector[], tamano)
{
	int i, j, mayor = vector[0];

	for(i = 0; i < TAMANO_VECTOR; i++)
	{
		if(vector[i] > mayor)
			mayor = vector[i];
	}

	return mayor;
}

void bubbleSortAscendente(int vector[], int tamano)
{
	int i, j, temp;

	for(i = 0; i < TAMANO_VECTOR; i++)
	{
		for(j = i + 1; j < TAMANO_VECTOR; j++)
		{
			if(vector[i] > vector[j])
			{
				temp = vector[i];
				vector[i] = vector[j];
				vector[j] = temp;
			}
		}
	}
}