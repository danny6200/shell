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
#include <ctype.h>
#include <fcntl.h>
#include <signal.h>
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

#define STAT_BUFF_SIZE 256

/* Function Prototypes */
void file(char **av);
int cd(char **av);
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
void __exit(int stat, char *f, size_t c);
void print_env(void);
void non_interactive(char **env, char *f_name, int count);
list_t env2linkd(char **env);
char *d2s(char *dynamic_str);
void nexec_cmd(char **av, char *file_name, size_t count);
void ngetfunc(char **av, char *f_name, size_t count);
void comment(char **arr);
/* helpers */
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
char *_strchr(const char *s, char c);
int _strcmp(char *s1, char *s2);
#endif /* main.h */
