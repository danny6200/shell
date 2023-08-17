#include "main.h"

/**
 * free_dp - frees char double pointer provided as an argument
 * @ptr: pointer to pointer that needs freeing
 */

void free_dp(char **ptr)
{
	int i;

	for (i = 0; ptr[i] != NULL; i++)
		free(ptr[i]);

	free(ptr);
}
