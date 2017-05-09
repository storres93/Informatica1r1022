#include "header.h"

int main(void)
{
	char string[MAX_LENGTH], stringToCompare[MAX_LENGTH];
	int compareResult;

	printf("Ingrese el primer string a comparar\n");
	scanf("%s", string);
	printf("Ingrese el segundo string a comparar\n");
	scanf("%s", stringToCompare);

	compareResult = my_strcmp(string, stringToCompare);

	switch(compareResult)
	{
	case 0:
		printf("Los strings son iguales\n");
		break;
	case 1:
		printf("El string %s es mayor que %s", string, stringToCompare);
		break;
	case -1:
		printf("El string %s es menor que %s\n", string, stringToCompare);
		break;
	}

	return 0;
}

//Return 0 when they are equal
//Return 1 when first string is greater than second;
//Return -1 when second string is greater than first;
int my_strcmp(char string[], char stringToCompare[])
{
	int i = 0, firstLength = my_strlen(string), secondLength = my_strlen(stringToCompare);

	if(firstLength > secondLength)
		return 1;

	if(firstLength < secondLength)
		return -1;

	while(string[i] == stringToCompare[i] && (string[i] != STRING_NULL && stringToCompare != STRING_NULL))
	{
		i++;
	}

	if(i == firstLength)
		return 0;

	if(string[i] > stringToCompare[i])
		return 1;
	else
		return -1;
}

int my_strcmp_2(char string[], char stringToCompare[])
{
	int i = 0;

	/* Runs till both strings are equal */
	while(string[i] == stringToCompare[i])
	{
		if(string[i] == STRING_NULL || stringToCompare[i] == STRING_NULL)
			break;

		i++;
	}

	if(string[i-1] == STRING_NULL && stringToCompare[i-1]==STRING_NULL)
		return 0;
	else if(string[i] > stringToCompare[i])
		return 1;
	else if(string[i] < stringToCompare[i])
		return -1;

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