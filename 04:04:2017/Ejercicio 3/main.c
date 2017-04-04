#include "header.h"

int main(void)
{
	int numeros[TAMANO_VECTOR], i;

	cargarVectorDeInt(numeros, TAMANO_VECTOR);

	bubbleSortAscendente(numeros, TAMANO_VECTOR);

	for(i = 0; i < TAMANO_VECTOR; i++)
	{
		printf("El elemento %d equivale a %d\n", i, numeros[i]);
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

void forceSortAscendente(int vector[], int tamano)
{
	int i, j, temp;

	for(i = 0; i < tamano; i++)
	{
		for(j = i + 1; j < tamano; j++)
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

void bubbleSortAscendente(int vector[], int tamano)
{
	int i, j, temp;

	for(i = 0; i < tamano; i++)
	{
		for(j = 0; j < tamano - i; j++)
		{
			if(vector[j] > vector[j + 1])
			{
				temp = vector[j];
				vector[j] = vector[j + 1];
				vector[j + 1] = temp;
			}
		}
	}
}

//Este algoritmo basicamente agarra un numero y se va fijando todos los anteriores hasta que encuentra uno menor y cambia su poscicion por ese
void insertionSortAscendente(int vector[], int tamano)
{
	int i, j, temp;
	for(i = 1; i < tamano; i++)
	{
		temp = vector[i];
		j = i-1;
		while(j>=0 && temp < vector[j])
		{
			vector[j+1] = vector[j];
			j--;
		}
		vector[j+1] = temp;
	}
}

void imprimirArray(int vector[], int tamano)
{
	int i;

	for(i = 0; i < tamano; i++)
	{
		printf("El elemento %d equivale a %d\n", i, vector[i]);
	}
}

/*
   Este metodo de sorting agarra el array y lo va partiendo a la mitad desde un pivot
   poniendo todos los numeros menores a la izquierda del pivot y los mayores a la derecha
 */
void quickSortAscendente(int vector[], int pivot, int lastIndex)
{
	if(pivot < lastIndex)
	{
		int pivotSecundario;
		pivotSecundario = partition(vector, pivot, lastIndex);
		quickSortAscendente(vector, pivot, pivotSecundario);
		quickSortAscendente(vector, pivotSecundario+1, lastIndex);
	}
}

int partition(int vector[], int pivotDado, int lastIndex)
{
	int i, j, pivot, temp;
	pivot = vector[pivotDado];
	i = pivotDado;
	j = lastIndex;
	while(1)
	{
		while(vector[i] < pivot && vector[i] != pivot)
			i++;
		while(vector[j] > pivot && vector[j] != pivot)
			j--;
		if(i < j)
		{
			temp = vector[i];
			vector[i] = vector[j];
			vector[j] = temp;
		}
		else
		{
			return j;
		}
	}
}