#include "main.h"


/**
 * print_env - gets the inherited env and printst them
 *
 */

void print_env(void)
{
	char **env = environ;
	int i = 0;

	while (env[i])
	{
		printf("%s", env[i]);
		i++;
	}
	printf("\n");
}
