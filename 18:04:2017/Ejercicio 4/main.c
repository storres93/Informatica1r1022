#include "header.h"

int main(void)
{
	int base, exponente;
	float pot;

	printf("Ingrese la base\n");
	scanf("%d", &base);
	printf("Ingrese el exponente\n");
	scanf("%d", &exponente);

	pot = potencia(base, exponente);

	printf("%d^%d = %f\n", base, exponente, pot);

	return 0;
}

//Sin tomar en cuenta los exponentes negativos
int potenciaPos(int base, int exponente)
{
	int res = base;

	if(exponente == 0)
		return 1;

	while(exponente > 1)
	{
		res *= base;
		exponente--;
	}

	return res;
}

//Tomando en cuenta los exponentes negativos
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