#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

void prompt(char *s);
extern char **environ;
int _putchar(char c);
void copy_string(char **arg, char *line_cpy);

char *_strcpy(char *dest, char *src);
ssize_t read_command(char *line_ptr, size_t n);
void rem_newline(char *line);
int fork_child(char **argv, char **arg);
int get_token(char **arg, char *line_ptr);

int leave_prog(char *line_ptr);

#endif /* #define MAIN_H */
