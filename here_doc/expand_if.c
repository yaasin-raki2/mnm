#include "../minishell.h"

// compare two strings
static int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

// add to a string
static char *ft_strjoin_plus(char *s1, char *s2)
{
	char *str;
	int i;
	int j;

	i = 0;
	j = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	if (ft_strlen(s1) > 0)
		str[i++] = '\n';
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);
}

static void open_here_doc(t_line *l)
{
	char *line;

	l->here_doc = (char *)malloc(sizeof(char) * 1);
	l->here_doc[0] = '\0';
	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(line, l->temp))
			break;
		l->here_doc = ft_strjoin_plus(l->here_doc, line);
	}
	printf("%s\n", l->here_doc);
}

static void here_doc_check(t_line *l, t_list *head)
{
	while (head)
	{
		if (!ft_strncmp((char *)head->content, "<<", 2))
		{
			head = head->next;
			if (head)
			{
				if (l->temp)
					free(l->temp);
				l->temp = ft_strdup(head->content);
				remove_quotes(l, '"');
				remove_quotes(l, '\'');
				deflag_in_quotes(l->temp);
				open_here_doc(l);
			}
		}
		if (head)
			head = head->next;
	}
}

void expand_if(t_line *l)
{
	int i;

	i = 0;
	while (l->arr[i])
	{
		here_doc_check(l, l->arr[i]);
		i++;
	}
}
