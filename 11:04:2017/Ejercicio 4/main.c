#include "header.h"

int main(void)
{
	char *phrase = NULL;
	size_t size;
	int words;

	printf("Ingrese la frase\n");
	getline(&phrase,&size,stdin);

	words = phraselen(phrase);

	printf("La frase tiene %d palabras\n", words);

	return 0;
}

int phraselen(char *phrase) {
	int words = 0, i = 0;
	while(phrase[i] != STRING_NULL)
	{

		while(phrase[i] != ' ' && phrase[i] != STRING_NULL) i++;

		if(phrase[i] != STRING_NULL) i++;
		words++;
	}

	return words;
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