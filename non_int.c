#include "main.h"

/**
 * non_interactive - handles the non interactive aspect of the
 * simple shell program.
 * @env: environmental variables
 * @fname: name of program
 * @c: command line count
 */

void non_interactive(__attribute__((unused)) char **env, char *fname, int c)
{
	char *buff = malloc(1024), *delim = "\n", **arr = NULL, **cmd = NULL;
	char *temp = NULL, *buff_h;
	ssize_t bytes_read;
	int i;

	if (buff == NULL)
		exit(0);

	buff_h = buff;
	while ((bytes_read = read(STDIN_FILENO, buff, 1024)) > 0)
	{
		buff[bytes_read - 1] = '\0';
		while (*buff == ' ' || *buff == '\n')
			buff++;
		arr = str2arr(buff, delim);
		if (arr == NULL)
		{
			free(buff_h);
			exit(0);
		}

		for (i = 0; arr[i] != NULL; i++)
		{
			temp = arr[i];
			cmd = str2arr(temp, " ");
			getfunc(cmd, fname, c);
			c++;
		}
		free(arr);
	}

	free(buff_h);
	exit(0);
}
