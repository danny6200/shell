#include "main.h"

/**
 * main - simple shell core. this is where the primary engine lives
 * Return: 0 success
 *
 */

int main(void)
{
	char *buff = NULL, *delim = " \n";
	char **arr;
	size_t len = 0;
	ssize_t read;
	int i = 0;

	while (1)
	{

		printf("#simple_shell$ ");
		read = getline(&buff, &len, stdin);
		if (read == -1)
		{

			printf("\n");
			exit(1);
		}
		arr = str2arr(buff, delim);
		printf("%p", arr[i]);

	}
	return (0);
}

/**
 * str2arr - performs tokenization of string recieved from main
 * @str - string to be tokenized
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
	a = malloc(i * sizeof(char*));
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
