#include "minishell.h"

void init_arr_list(t_line *l)
{
    int len;

    len = 0;
    while (l->pipedout[len])
        len++;
    l->arr = (t_list **)malloc(sizeof(t_list *) * len + 1);
}

void parse_chunks(t_line *l, int x)
{
    int     i;

    i = 0;
    l->arr[x] = NULL;
    while (l->chunks[x][i])
    {
        split_plus_plus(l->chunks[x][i], x, l);
        i++;
    }
}

int get_arr_len(char **arr)
{
    int len;

    len = 0;
    while (arr[len])
        len++;
    return (len);
}

void fillup_arr_list(t_line *l)
{
    int i;
    int len;

    i = 0;
    len = get_arr_len(l->pipedout);
    l->chunks = (char ***)malloc(sizeof(char **) * (len + 1));
    l->arr = (t_list **)malloc(sizeof(t_list *) * (len + 1));
    while (l->pipedout[i])
    {
        l->chunks[i] = ft_split(l->pipedout[i], ' ');
        parse_chunks(l, i);
        i++;
    }
    l->chunks[i] = NULL;
    l->arr[i] = NULL;
}

void parse_line(t_line *l)
{
    flag_in_quotes(l);
    init_arr_list(l);
    fillup_arr_list(l);
    expand_if(l);
	print_arr_list(l->arr);
}

int	main()
{
	t_line *l;

	l = (t_line *)malloc(sizeof(t_line));
    l->temp = NULL;
	while (1)
	{
		l->line = readline("$> ");
        if (!l->line)
            break;
        add_history(l->line);
		parse_line(l);
        free(l->line);
        //system("leaks minishell");
	}
	return (0);
}
