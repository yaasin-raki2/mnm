#include "minishell.h"

// TODO: Expand and remove quotes

void split_plus_plus(char *str , int x, t_line *l)
{
    int i;
    int s;
    char *temp;

    i = 0;
    while(str[i])
    {
        s = i;
        if (str[i] != '<' && str[i] != '>')
        {
            while (str[i] && str[i] != '<' && str[i] != '>')
                i++;
            temp = ft_substr(str, s, i - s);
            ft_lstadd_back(&l->arr[x], ft_lstnew(temp));
            if (!str[i])
                break;
        }
        s = i;
        if (str[i] == '<' || str[i] == '>')
        {
            if (str[i + 1] && (str[i] == '<' && str[i + 1] == '<'))
            {
                temp = ft_substr(str, s, i - s + 2);
                i++;
            }
            else if (str[i +1] && (str[i] == '>' && str[i + 1] == '>'))
            {
                temp = ft_substr(str, s, i - s + 2);
                i++;
            }
            else
                temp = ft_substr(str, s, i - s + 1);
            ft_lstadd_back(&l->arr[x], ft_lstnew(temp));
        }
        i++;
    }
}
