#include "main.h"

/**
 * main - simple shell core. this is where the primary engine lives
 * Return: 0 success
 *
 */

int main(int ac, char **av, __attribute__((unused)) char **env)
{
	char *buff = NULL, *delim = " \n", *f_name = av[0];
	size_t len = 0;
	ssize_t read;
	(void)ac;

	while (1)
	{
	Point:
		printf("#simple_shell$ ");
		read = getline(&buff, &len, stdin);
		if (read == -1)
		{
			printf("\n");
			exit(1);
		}
		else if (strcmp(buff, "\n") == 0)
			goto Point;

		av = str2arr(buff, delim);
		getfunc(av, f_name);
	}
	len = 0;
	while (av[len])
	{
		free(av[len]);
		len++;
	}
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
	while (arr[i] != NULL)
	{
		i++;
		arr[i] = strtok(NULL, delim);
	}
	arr[i] = NULL;
	a = malloc(i * sizeof(char *));
	if (a == NULL)
		exit(1);
	for (n = 0; n < i; n++)
	{
		a[n] = strdup(arr[n]);
		if (a[n] == NULL)
		{
			perror("Memory allocation error");
			exit(1);
		}
	}
	free(arr);
	return (a);
}
/**
 * chck_cmd - checks if command is valid
 * @av: argument vector
 *
 * Return: nothing
 */
void chck_cmd(char **av, char *file_name)
{
	unsigned int i;
	struct stat st;
	char **env = environ;

	(void)i;
	if (stat(av[0], &st) == 0)
	{
		if (execve(av[0], av, env) == -1)
		{
			fprintf(stdout, "%s: 1: %s: not found\n", file_name, av[0]);
			exit(1);
		}
	}
	else
	{
		fprintf(stdout, "%s: 1: %s: not found\n", file_name, av[0]);
		exit(1);
	}
}


/**
 * getfunc - handles all functions from main
 * @av: array of arguments feom mamin
 * Return: 0 or -1
 */

void getfunc(char **av, char *f_name)
{
	int status;
	pid_t child;

	if (strcmp(av[0], "exit") == 0)
		__exit(av[1]);
	if (strcmp(av[0], "env") == 0)
		print_env();
	child = fork();
	if (child == 0)
		chck_cmd(av, f_name);
	else
		wait(&status);
}
