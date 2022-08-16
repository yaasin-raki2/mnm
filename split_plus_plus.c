#include "minishell.h"

void split_plus_plus(char *str , int x)
{
    int i;
    int s;

    i = 0;
    while(str[i])
    {
        s = i;
        if (str[i] != '<' && str[i] != '>')
        {
            while (str[i] && str[i] != '<' && str[i] != '>')
                i++;
        }
    }
}