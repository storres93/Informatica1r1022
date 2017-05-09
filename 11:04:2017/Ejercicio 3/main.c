#include "header.h"

int main(void)
{
	char string[MAX_LENGTH], string2[MAX_LENGTH], finalString[MAX_LENGTH];
	int concatResult;

	printf("Ingrese el primer string a concatenar\n");
	scanf("%s", string);
	printf("Ingrese el segundo string a concatenar\n");
	scanf("%s", string2);

	concatResult = my_strconcat(string, string2, finalString);

	if(concatResult)
		printf("Los strings son demasiado largos\n");
	else
		printf("El string final es %s\n", finalString);

	return 0;
}

//Return 0 when they are equal
//Return -1 if string is too large;
int my_strconcat(char string[], char string2[],char stringDestino[])
{
	int i = 0, j = 0, firstLength = my_strlen(string), secondLength = my_strlen(string2);

	if((firstLength + secondLength - 1) > MAX_LENGTH)
		return -1;

	while(string[i] != STRING_NULL)
	{
		stringDestino[i] = string[i];
		i++;
	}

	while(string2[j] != STRING_NULL)
	{
		stringDestino[i] = string2[j];
		i++;
		j++;
	}

	stringDestino[i] = '\0';

	return 0;
}

int my_strlen(char string[])
{
	int length = 0;
	while(string[length] != STRING_NULL)
	{
		length++;
	}

	return length;
}