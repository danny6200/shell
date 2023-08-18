#include "main.h"

/**
 * main - simple shell core. this is where the primary engine lives
 * @ac: argument count
 * @av: argument vector
 * @env: environment vector
 *
 * Return: 0 success
 *
 */

int main(int ac, char **av, char **env)
{
	char *buff = NULL, *delim = " \n", *f_name = av[0];
	size_t len = 0, count = 0;
	ssize_t read;
	(void)ac;

	while (1)
	{
Point:
		count++;
		if (!(isatty(STDIN_FILENO)))
			non_interactive(env, f_name, count);
		else
		{
			printf("$ ");
			read = getline(&buff, &len, stdin);
			if (read == -1)
			{
				free(buff);
				printf("\n");
				exit(1);
			}
			av = str2arr(buff, delim);
			free(buff);
			buff = NULL;
			if (av == NULL)
				goto Point;
			getfunc(av, f_name, count);
		}
		free_dp(av);
		/* free(buff); */
	}
	free_dp(av);
	free(buff);
	return (0);
}

/**
 * str2arr - performs tokenization of string recieved from main
 * @str: string to be tokenized
 * @delim: delimiter seperatimg each entry
 * Return: pointer to array of tokens
 */

char **str2arr(char *str, char *delim)
{
	int i = 0, n;
	char **arr, **a;

	arr = malloc(strlen(str) * sizeof(char *));
	arr[i] = strtok(str, delim);
	if (arr[i] == NULL)
	{
		free(arr);
		return (NULL);
	}
	while (arr[i] != NULL)
	{
		i++;
		arr[i] = strtok(NULL, delim);
	}
	a = malloc((i + 1) * sizeof(char *));
	if (a == NULL)
	{
		free(arr);
		return (NULL);
	}
	for (n = 0; n < i; n++)
	{
		a[n] = strdup(arr[n]);
		if (a[n] == NULL)
		{
			free_dp(a);
			free(arr);
			return (NULL);
		}

	}
	a[i] = NULL;
	free(arr);
	return (a);
}

/**
 * chck_cmd - checks if command is valid
 * @av: argument vector
 * @file_name: name of shell executable
 * @count: line count
 * Return: nothing
 */
void chck_cmd(char **av, char *file_name, size_t count)
{
	unsigned int i, n = count;
	struct stat st;
	char **env = environ;

	(void)i;
	if (stat(av[0], &st) == 0)
	{
		if (execve(av[0], av, env) == -1)
		{
			fprintf(stdout, "%s: %u: %s: not found\n", file_name, n, av[0]);
			return;
		}
	}
	else
	{
		fprintf(stdout, "%s: %u: %s: not found\n", file_name, n, av[0]);
		return;
	}
}


/**
 * getfunc - handles all functions from main
 * @av: array of arguments feom mamin
 * @f_name: name of shell executable
 * @count: line count
 * Return: 0 or -1
 */

void getfunc(char **av, char *f_name, size_t count)
{
	int status;
	pid_t child;
	char *exit_code = av[1];

	if (strcmp(av[0], "exit") == 0)
	{
		free_dp(av);
		__exit(exit_code);
	}
	else if (strcmp(av[0], "env") == 0)
	{
		free_dp(av);
		print_env();
		return;
	}
	child = fork();
	if (child == 0)
	{
		chck_cmd(av, f_name, count);
		exit(0);
	}
	else
		wait(&status);
}
