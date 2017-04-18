#include "header.h"

int main(void)
{
	float max;

	max = maximoYMinimo(1);

	printf("El maximo es %f\n", max);

	return 0;
}

float maximo()
{
	int continuar = 0;
	float aux, max;

	do
	{
		printf("Ingrese un numero\n");
		scanf("%f", &aux);

		if(continuar == 0)
			max = aux;

		if(aux > max)
			max = aux;

		printf("Desea ingresar otro numero? (1 si, 0 no)\n");
		scanf("%d", &continuar);
	} while(continuar != 0);

	return max;
}

float minimo()
{
	int continuar = 0;
	float aux, min;

	do
	{
		printf("Ingrese un numero\n");
		scanf("%f", &aux);

		if(continuar == 0)
			min = aux;

		if(aux < min)
			min = aux;

		printf("Desea ingresar otro numero? (1 si, 0 no)\n");
		scanf("%d", &continuar);
	} while(continuar != 0);


	return min;
}

float maximoYMinimo(int devolucion)
{
	int retorno;

	if(devolucion)
	{
		retorno = maximo();
	} else {
		retorno = minimo();
	}

	return retorno;
}