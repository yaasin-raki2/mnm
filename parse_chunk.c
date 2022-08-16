#include "minishell.h"

int get_arr_len(char **arr)
{
    int len;

    len = 0;
    while (arr[len])
        len++;
    return (len);
}

void free_dd_arr(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void parse_chunks(t_line *l)
{
    int     i;

    i = 0;
    while (l->chunks[i])
    {
        split_plus_plus(l->chunks[i], i);
        i++;
    }
}