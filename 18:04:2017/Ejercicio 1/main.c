#include "header.h"

int main(void)
{
	float prom;

	prom = promedio();

	printf("El promedio es %f\n", prom);

	return 0;
}

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