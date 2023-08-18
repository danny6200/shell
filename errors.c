#include "main.h"
/**
 * __exit - exits program with or without code printed
 * @str: code to be printed
 */

void __exit(char *str)
{
	if (str == NULL)
	{
		exit(0);
	}
	else
	{
		printf("%s\n", str);
		exit(atoi(str));
	}
}
