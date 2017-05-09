#include "header.h"

int main(void)
{
	char string[MAX_LENGTH];

	scanf("%s", string);

	printf("El string %s tiene %d caracteres\n", string, my_strlen(string));

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
