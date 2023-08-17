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
	char *buff = malloc(1024), *delim = "\n", **arr = NULL, **cmd = NULL;
	char *temp = NULL;
	ssize_t bytes_read;
	int i;

	if (buff == NULL)
		exit(0);

	while ((bytes_read = read(STDIN_FILENO, buff, 1024)) > 0)
	{
		buff[bytes_read -1] = '\0';
		while (*buff == ' ' || *buff == '\n')
			buff++;
		arr = str2arr(buff, delim);
		 /* for (i = 0; arr[i] != NULL; i++) */
		 /* 	printf("%s\n", arr[i]); */
		if (arr == NULL)
			exit(0);

		for (i = 0; arr[i] != NULL; i++)
		{
			temp = arr[i];
			cmd = str2arr(temp, " ");
			getfunc(cmd, fname, count);
			count++;
		}
	}

	exit(0);
}
