#include "header.h"

int main(void)
{
	float temperaturaActual, temperaturaMaxima = -1, temperaturaMinima = -1, temperaturaPromedio = 0;
	int cantidadDebajo4YArriba50, cantidadEntre20Y45, contadorTemperaturas = 0;

	printf(MENSAJE_BIENVENIDA_TEMPERATURAS);
	scanf("%f", temperaturaActual);

	temperaturaMaxima = temperaturaMinima = temperaturaActual;
	while(temperaturaActual >= 0)
	{
		contadorTemperaturas++;

		temperaturaPromedio += temperaturaActual;

		if(temperaturaActual > temperaturaMaxima)
			temperaturaMaxima = temperaturaActual;

		if(temperaturaActual < temperaturaMinima)
			temperaturaMinima = temperaturaActual;

		if(temperaturaActual < 4 || temperaturaActual > 50)
			cantidadDebajo4YArriba50++;

		if(temperaturaActual > 20 && temperaturaActual < 45)
			cantidadEntre20Y45++;

		printf(MENSAJE_BIENVENIDA_TEMPERATURAS);
		scanf("%f", temperaturaActual);
	}

	printf("La temperatura promedio es %f\n", temperaturaPromedio / (float)contadorTemperaturas);
	printf("La temperatura maxima es %f\n", temperaturaMaxima);
	printf("La temperatura minima es %f\n", temperaturaMinima);
	printf("Hubieron %d temperaturas menores a 4C o mayores a 50C\n", cantidadDebajo4YArriba50);
	printf("Hubieron %d temperaturas entre 20zC o mayores a 45C\n", cantidadEntre20Y45);

	return 0;
}