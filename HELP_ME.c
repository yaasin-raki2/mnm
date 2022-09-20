#include "minishell.h"

void print_list(t_list *head)
{
    char *str;

    while (head)
    {
        str = (char *)(head->content);
        printf("(%s)=>", str);
        head = head->next;
    }
    printf("(NULL)\n");
}

void print_arr_list(t_list **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        print_list(arr[i]);
        i++;
    }
}

void print_dd_arr(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        printf("%s\n", arr[i]);
        i++;
    }
}