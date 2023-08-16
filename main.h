#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>


/**
 * struct list - environmental variables linked list
 * @env: environmental variable
 * @next: next node
 */
typedef struct list
{
	char *env;
	struct list *next;

} list_t;






char *_strtok(char *str, const char *delim);
char **str2arr(char *str, char *delim);
void chck_cmd(char **av, char *file_name, size_t count);
void getfunc(char **av, char *f_name, size_t count);
extern char **environ;
char **str2arr(char *str, char *delim);
void err(char *error_type);
void __exit(char *str);
void print_env(void);
void non_interactive(char **env, char * f_name, int count);
list_t env2linkd(char **env);



#endif /* main.h */
