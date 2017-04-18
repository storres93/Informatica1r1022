#include "header.h"

int main(void)
{
	int pares;

	pares = paresEImpares(1);

	printf("El hay %d numeros pares\n", pares);

	return 0;
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

int paresEImparesV2(int devolucion)
{
	int continuar, aux, impares = 0, pares = 0;

	do
	{
		printf("Ingrese un numero\n");
		scanf("%d", &aux);

		if((aux % 2) != 0)
			impares++;
		else
			pares++;

		printf("Desea ingresar otro numero? (1 si, 0 no)\n");
		scanf("%d", &continuar);
	} while(continuar != 0);

	return (devolucion) ? pares : impares;
}