#include "header.h"

// Si el resto de la division = 0 se que es divisible por ende es Multiplo
int Multiplo(int valorDeAnalisis, int divisor)
{
	int resultado = ERROR;

	if(valorDeAnalisis % resultado == 0)
	{
		resultado = OK;
	}

	return resultado;
}

//El factorial de un numero se define como la multiplicacion de todos los numeros previos
// !0 = 1 ^ !4 = 4 * 3 * 2 * 1
unsigned int Factorial(int n)
{
	unsigned int factorial = 1;

	while(n > 0)
	{
		factorial *= n--;
	}

	return factorial;
}

unsigned int Fibonacci(int n)
{
	unsigned int actual = 1, anterior = 0, resultado;
	int i;

	if(n == 0)
	{
		resultado = anterior;
	}
	else if(n == 1)
	{
		resultado = actual;
	}
	else
	{
		for(i = 1; i < n; i++)
		{
			resultado = actual + anterior;
			anterior = actual;
			actual = resultado;
		}
	}

	return resultado;
}