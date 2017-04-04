#include "header.h"

int main(void)
{
	int numeros[TAMANO_VECTOR], numerosRepetidos[TAMANO_VECTOR] = { 0 }, cantidadRepetidos = 0, i;

	cargarVectorDeInt(numeros, TAMANO_VECTOR);

	cantidadRepetidos = contarRepetidos(numeros, TAMANO_VECTOR);

	encontrarRepetidos(numeros, numerosRepetidos, TAMANO_VECTOR);

	printf("Hay %d elementos repetidos\n", cantidadRepetidos);

	for(i = 0; i < TAMANO_VECTOR; i++)
	{
		if(numerosRepetidos[i])
		{
			printf("El elemento %d se repite %d veces\n", numeros[i], numerosRepetidos[i]);
		}
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

int contarRepetidos(int vector[], int tamano)
{
	int i, j, repetidos;

	for(i = 0, repetidos = 0; i < tamano; i++)
	{
		for(j = i + 1; j < tamano; j++)
		{
			if(vector[i] == vector[j])
				repetidos++;
		}
	}

	return repetidos;
}

int estaPreviamente(int vector[], int indiceRepetido, int tamano)
{
	int i = indiceRepetido - 1, repetido = 0;

	while(repetido == 0 && i >= 0)
	{
		if(vector[i] == vector[indiceRepetido])
		{
			repetido++;
		}
		i--;
	}

	return repetido;
}

void encontrarRepetidos(int vector[], int vectorRepetidos[], int tamano)
{
	int i, j;

	for(i = 0; i < tamano; i++)
	{
		for(j = i + 1; j < tamano; j++)
		{
			if(vector[i] == vector[j] && !estaPreviamente(vector, i, tamano))
				vectorRepetidos[i]++;
		}
	}
}
