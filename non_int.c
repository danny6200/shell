#include "main.h"

/**
 * non_interactive - handles the non interactive aspect of the
 * simple shell program.
 * @env: environmental variables
 * @fname: name of program
 * @count: command line count
 */

void non_interactive(__attribute__((unused)) char **env, char *fname, int count)
{
	char *buff = malloc(1024), *delim = "\n", **arr, **cmd, *temp;
	ssize_t bytes_read;
	int i;

	bytes_read = read(STDIN_FILENO, buff, 1024);

	if (bytes_read == -1)
		exit(0);
	arr = str2arr(buff, delim);
	if (arr == NULL)
	{
		free(buff);
		exit(0);
	}
	free(buff);
	for (i = 0; arr[i] != NULL; i++)
	{
		temp = arr[i];
		cmd = str2arr(temp, " ");
		getfunc(cmd, fname, count);
		count++;
	}

	exit(0);
}
