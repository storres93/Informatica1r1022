#include "header.h"

int main(void)
{
	int operacion = 0;
	float resultado, num1, num2;

	do
	{
		printf("Ingrese la operacion que desea realizar\n1 - Sumar dos numeros\n2 - Restar dos numeros\n3 - Multiplicar dos numeros\n4 - Dividir dos numeros\n5 - Calcular la potencia de un numero\n6 - Calcular el promedio de un set de datos\n7 - Calcular el maximo y el minimo de un set de datos\n8 - Calcular la cantidad de pares e impares de un set de datos\n0 - Salir del programa\n");

		scanf("%d", &operacion);

		switch (operacion) {
		case 1: //Suma
			printf("Ingrese los dos numeros a sumar como '<num1>+<num2>'\n");
			scanf("%f+%f", &num1, &num2);
			resultado = suma(num1, num2);
			printf("%f + %f = %f\n\n", num1, num2, resultado);
			break;
		case 2: //Resta
			printf("Ingrese los dos numeros a restar como '<num1>-<num2>'\n");
			scanf("%f-%f", &num1, &num2);
			resultado = resta(num1, num2);
			printf("%f - %f = %f\n\n", num1, num2, resultado);
			break;
		case 3: //Multiplicacion
			printf("Ingrese los dos numeros a multiplicar como '<num1>*<num2>'\n");
			scanf("%f*%f", &num1, &num2);
			resultado = multiplicacion(num1, num2);
			printf("%f * %f = %f\n\n", num1, num2, resultado);
			break;
		case 4: //Division
			printf("Ingrese los dos numeros a dividir como '<num1>/<num2>'\n");
			scanf("%f/%f", &num1, &num2);
			resultado = division(num1, num2);
			printf("%f / %f = %f\n\n", num1, num2, resultado);
			break;
		case 5: // Potencia
			printf("Ingrese la potencia como <base>^<exponente>\n");
			scanf("%f^%f", &num1, &num2);
			resultado = potencia(num1, num2);
			printf("%f^%f = %f\n\n", num1, num2, resultado);
			break;
		case 6: // Promedio
			resultado = promedio();
			printf("El promedio es %f\n", resultado);
			break;
		case 7: // Maximo y minimo
			printf("Desea sacar el maximo(1) o el minimo(0)?\n");
			scanf("%f", &num1);
			resultado = maximoYMinimo((int)num1);
			printf("El resultado es %f\n\n", resultado);
			break;
		case 8: //Cantidad de pares e impares
			printf("Desea sacar la cantidad de pares(1) o de impares(0)?");
			scanf("%f", &num1);
			resultado = (float)maximoYMinimo((int)num1);
			printf("El resultado es %f\n\n", resultado);
			break;

		default:
			operacion = 0;
			break;
		}

	} while(operacion);

	printf("Gracias por operar con la calculadora UTN\n");

	return 0;
}