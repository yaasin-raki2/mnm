#include "minishell.h"

void parse_chunks(t_line *l)
{
    int     i;

    i = 0;
    while (l->chunks[i])
    {
        split_plus_plus(l->chunks[i], i, l);
        i++;
    }
}