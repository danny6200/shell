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

/**
 * struct stat - an inbuilt struct to keeps file stats
 * 
 */
struct stat st;

/* Function Prototypes */

void free_dp(char **ptr);
char *_strtok(char *str, const char *delim);
char *_getpath(char *cmd);
char **str2arr(char *str, char *delim);
void exec_cmd(char **av, char *file_name, size_t count);
int chck_cmd(char *cmd);
void getfunc(char **av, char *f_name, size_t count);
extern char **environ;
char **str2arr(char *str, char *delim);
void err(char *error_type);
void __exit(char *str);
void print_env(void);
void non_interactive(char **env, char * f_name, int count);
list_t env2linkd(char **env);

#endif /* main.h */
