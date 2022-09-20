#ifndef MINISHELL_MINISHELL_H
#define MINISHELL_MINISHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"

typedef struct s_line
{
	char *line;
	char *command;
	char *args;
	char **pipedout;
	t_list **arr;
	char ***chunks;
	char **env;
	char *expanded_var;
	char *temp;
	char *here_doc;
} t_line;

void parse_line(t_line *l);
void flag_in_quotes(t_line *l);
void init_arr_list(t_line *l);
void fillup_arr_list(t_line *l);
void parse_chunks(t_line *l, int x);

void split_plus_plus(char *str, int x, t_line *l);

void flag_in_quotes(t_line *l);
void deflag_in_quotes(char *str);
void remove_quotes(t_line *l, char quote_type);

void remove_one(t_line *l, int x);
void build_it(t_line *l, int x);
void expand_it(t_line *l);

void expand_if(t_line *l);

void print_list(t_list *head);
void print_arr_list(t_list **arr);

#endif // MINISHELL_MINISHELL_H

// TODO: HD: Append to a string each line you recieve after parsing it.

// TODO: HD: Handle here_doc nesting.