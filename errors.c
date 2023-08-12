#include "main.h"

/**
 * err - prints errors according to the requirement
 * @error_type: type of error to be printed
 */

void err(char *error_type)
{
	if (strcmp(error_type, "mem") == 0)
		perror("Error: Memory Allocation Failed");
	else if (strcmp(error_type, "use") == 0)
		perror("Usage: simple_shell");
	else if (strcmp(error_type, "tok") == 0)
		perror("Error: Tokenization Failed");
	else
		perror("Unknown Error");

	exit(1);
}
