#include "header.h"

int main(void)
{
	int i, valorDeAnalisis;

	printf("Por favor ingrese el numero del cual quiere descubrir sus multiplos que sea entero positivo\n");
	scanf("%d", &valorDeAnalisis);

	if(valorDeAnalisis >= 0)
	{
		printf("Los multiplos del %d, del 1 al 20 son:\n", valorDeAnalisis);
		for(i = 1; i < MAX_MULTIPLOS; i++)
		{
			if(Multiplo(valorDeAnalisis, i) == OK)
				printf("%d\n", i);
		}
	}
	else
	{
		printf("Ah ingresado un numero invalido\n");
	}

	return 0;
}