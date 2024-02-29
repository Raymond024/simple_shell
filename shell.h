#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_ARG 125

extern char **environ;

int executecmd(char *argsC[]);
int commandread(void);
char *erasenull(char *string, int leng);
int tokenizer(char *command, char *argsC[]);
char *get_path(const char *program_name);
void dis_prompt(void);

#endif
