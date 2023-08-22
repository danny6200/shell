#include "main.h"

/**
 * print_env - prints the environmental variable
 */

void print_env(void)
{
	char **env = environ;
	int i;

	for (i = 0; env[i] != NULL; i++)
		printf("%s\n", env[i]);

}
