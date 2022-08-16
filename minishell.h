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
	char    *line;
	char    *command;
	char    *args;
    char    **pipedout;
    t_list  **arr;
    char    **chunks;
} t_line;

void    parse_line(t_line *l);
void    flag_in_quotes(t_line *l);
void    init_arr_list(t_line *l);
void    fillup_arr_list(t_line *l);
t_list  parse_chunk(t_line *l);

char    **split_plus_plus(char *str);

void    print_list(t_list *head);
void    print_arr_list(t_list **arr);

#endif //MINISHELL_MINISHELL_H
