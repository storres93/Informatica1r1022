#include "header.h"

float promedio()
{
	int continuar, cantidad = 0;
	float aux, sum = 0;

	do
	{
		cantidad++;
		printf("Ingrese un numero\n");
		scanf("%f", &aux);
		sum += aux;

		printf("Desea ingresar otro numero? (1 si, 0 no)\n");
		scanf("%d", &continuar);
	} while(continuar != 0);

	return sum / cantidad;
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

int pares()
{
	int continuar, aux, pares = 0;

	do
	{
		printf("Ingrese un numero\n");
		scanf("%d", &aux);

		if((aux % 2) == 0)
			pares++;

		printf("Desea ingresar otro numero? (1 si, 0 no)\n");
		scanf("%d", &continuar);
	} while(continuar != 0);

	return pares;
}

int impares()
{
	int continuar, aux, impares = 0;

	do
	{
		printf("Ingrese un numero\n");
		scanf("%d", &aux);

		if((aux % 2) != 0)
			impares++;

		printf("Desea ingresar otro numero? (1 si, 0 no)\n");
		scanf("%d", &continuar);
	} while(continuar != 0);

	return impares;
}

int paresEImpares(int devolucion)
{
	int retorno;

	if(devolucion)
	{
		retorno = pares();
	} else {
		retorno = impares();
	}

	return retorno;
}

float potencia(int base, int exponente)
{
	float res = (exponente > 0) ? base : 1/(float)base;

	if(exponente == 0)
		return 1;

	while(exponente > 1 || exponente < -1)
	{
		res = (exponente > 0) ? res * (float)base : res/(float)base;
		exponente = (exponente > 0) ? exponente - 1 : exponente + 1;
	}

	return res;
}

float suma(float num1, float num2)
{
	return num1 + num2;
}

float resta(float num1, float num2)
{
	return num1 - num2;
}

float division(float num1, float num2)
{
	return num1 / num2;
}

float multiplicacion(float num1, float num2)
{
	return num1 * num2;
}