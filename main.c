#include "minishell.h"

// Traverse the string until you find a double quotes, then search for the end of it
// While doing so flag space or pipe as a non printable character
void flag_in_quotes(t_line *l)
{
    int i;
    int j;

    i = 0;
    while (l->line[i])
    {
        if (l->line[i] == '"')
        {
            j = i + 1;
            while (l->line[j] && l->line[j] != '"')
            {
                if (l->line[j] == '|')
                    l->line[j] = -1;
                else if (l->line[j] == ' ')
                    l->line[j] = -2;
                j++;
            }
            break;
        }
        i++;
    }
    l->pipedout = ft_split(l->line, '|');
}

void init_arr_list(t_line *l)
{
    int len;

    len = 0;
    while (l->pipedout[len])
        len++;
    l->arr = (t_list **)malloc(sizeof(t_list *) * len + 1);
}



void fillup_arr_list(t_line *l)
{
    int i;

    i = 0;
    while (l->pipedout[i])
    {
        l->chunks = ft_split(l->pipedout[i], ' ');
        l->arr[i] = parse_chunk(l);
        i++;
    }
}

void parse_line(t_line *l)
{
    flag_in_quotes(l);
    init_arr_list(l);
    fillup_arr_list(l);
    print_arr_list(l->arr);
}

int	main()
{
	t_line *l;

	l = (t_line *)malloc(sizeof(t_line));
	while (1)
	{
		printf("$> ");
		l->line = readline(NULL);
		parse_line(l);
        system("leaks minishell");
	}
	return (0);
}
