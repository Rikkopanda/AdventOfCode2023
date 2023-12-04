

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int  i;
	char *s1;
	
	s1 = (char *)s;
	i = 0;
	if(c > 256)
		c = c - 256;
	while(s1[i] != '\0')
	{
		if(s1[i] == c)
		{
			s1 = &s1[i];
			return (s1);
		}
		i++;
	}
	if(s1[i] == c)
			return (&s1[i]);
	return (NULL);
}

t_list *ft_lstnew_strdup(void *buffer)
{
	char *new_str;
	char *str;
	size_t i;
	t_list *rtn;

	i = 0;
	str = buffer;
	if(!buffer)// check even of alle chars /0... Mag /0's? wanneer niet
		return (NULL);
	while(str[i])
		i++;
	new_str = (char *)malloc(sizeof(char) * i + 1);
	if(!new_str)
		return (NULL);
	i = 0;
	while(str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	rtn = (t_list *)malloc(sizeof(t_list));
	if(!rtn)
		return (NULL);
	(*rtn).buffer = new_str;
	(*rtn).next = NULL;
	return (rtn);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	if(!lst || !new)
		return ;
	if(*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

t_list *ft_lstlast(t_list *lst)
{
	t_list *current;

	if(lst == NULL)
		return (0);
	current = lst;
	while(current->next != NULL)
		current = current->next;
	return (current);
}

void ft_lstclear(t_list **lst)
{
	t_list *tmp;
	int found_newline;

	found_newline = 0;
	if (!lst || !*lst)
		return ;
	if (lst)
	{
		while (*lst)
		{
			if(!find_newline(*lst))
				found_newline = 1;
			tmp = (*lst)->next;
			free((*lst)->buffer);
			(*lst)->buffer = 0;
			free((*lst));
			*lst = 0;
			*lst = tmp;
			if(found_newline)
				break;
		}//*tmp van new node na node met \n wordt nu eerste node (*lst)
	}
	//if(left_over)
	//	free(left_over);
}
//printf("first buffer %s", tmp->buffer);