
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>
# include "get_next_line.h"
# include "../libft/libft.h"

void free_arr(char *ptr[15000])
{
	int i;

	i = 0;
	while(ptr[i])
	{
		free(ptr[i]);
		i++;
	}
}

typedef struct n
{
	char *nodename;
	node *left;
	node *right;
} node;

node *save_new(char *str)
{
	node new_node;
	new_node.nodename = str;
	return(&new_node);
}


node *first_node(char *str)
{
	node new_node;
	char **splitstr;
	splitstr = ft_split(str, ' ');

	ft_strtrim(splitstr[2], "(,");
	ft_strtrim(splitstr[3], ")");
	new_node.nodename = splitstr[0];
	new_node.left = save_new(splitstr[2]);
	new_node.right = save_new(splitstr[3]);
	free(splitstr);
}

int main(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);

    char *totalstr[15000];
    char *next_line;
    int j;
	fd = open(argv[1], O_RDONLY);
	next_line = (char *)1;

    j = 0;
    totalstr[j] = (char *)1;
	int start;
	node *start;
	node *current;

	start = 0;
	while(1)
	{
        totalstr[j] = get_next_line(fd);
        if(totalstr[j] == NULL)
            break ;
		if(ft_strnstr(totalstr[j], "AAA", 4))
			start = 1;
		if(start == 1)
		{
			start = first_node(totalstr[j]);
			start = 0;
		}
		//printf("%s strlen %d", totalstr[j], (int)strlen(totalstr[j]));
        j++;
	}
    //printf("%s strlen \n\n", totalstr[j]);

	j = 0;
	while(totalstr[j])
	{
		//			start = 2;
		//	current = start;
		//else if(start == 2)
		//{
		//	if(cmp_str_withnext())
		//	current = current->left;
		//	current = current->right;
		//}

	}


	free_arr(totalstr);
    close(fd);
}