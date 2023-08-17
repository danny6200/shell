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

/* struct stat declaration */
struct stat st;

/* Function Prototypes */
char *_strtok(char *str, const char *delim);
char *_getenv(char *name);
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
int _strcmp(char *str1, char *str2);

#endif /* main.h */
