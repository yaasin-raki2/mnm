#include "../minishell.h"

static void rm_q(t_line *l, char quote_type, int n)
{
    int i;
    int j;
    char *new;

    new = (char *)malloc(sizeof(char) * (ft_strlen(l->temp) - n + 1));
    i = 0;
    j = 0;
    while (l->temp[i])
    {
        if (l->temp[i] == quote_type)
            i++;
        else
            new[j++] = l->temp[i++];
    }
    new[j] = '\0';
    free(l->temp);
    l->temp = new;
}

void remove_quotes(t_line *l, char quote_type)
{
    int n;
    int i;

    n = 0;
    i = 0;
    while (l->temp[i])
    {
        if (l->temp[i] == quote_type)
            n++;
        i++;
    }
    rm_q(l, quote_type, n);
}