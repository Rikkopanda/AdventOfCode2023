
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
//#include "../Libft/libft.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"

typedef struct list
{
	char *buffer;
	struct list *next;
}	t_list;



char *get_next_line(int fd);
char *make_next_line(t_list **list, int size);
int size_of_total_str(t_list **list);
void make_new_list(t_list **list, char *after_newlinestr);
char *ret_next_line(t_list **list);
int size_of_total_str(t_list **list);
char *create_list(int fd, t_list **list);
int find_newline(t_list *node);

//Helpers
char	*ft_strchr(const char *s, int c);
t_list *ft_lstnew_strdup(void *buffer);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
t_list *ft_lstlast(t_list *lst);
size_t ft_strlen(const char *s);
void ft_lstclear(t_list **lst);

#endif