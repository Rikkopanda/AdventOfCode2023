
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>
# include "get_next_line.h"




int look_for_symbols(char **total, int *i, int tmp_j)
{
	if(total[*i + 1] != NULL)
		if(tmp_j < strlen(total[*i + 1]))
			if(total[*i + 1][tmp_j] >= '!' && total[*i][tmp_j] <= '/')
				return (1);
	if(*i >= 1)
		if(total[*i - 1][tmp_j] >= '!' && total[*i - 1][tmp_j] <= '/')
			return (1);
	if(tmp_j >= 1)
		if(total[*i][tmp_j - 1] >= '!' && total[*i][tmp_j - 1] <= '/')
			return (1);
	int len = strlen(total[*i]);
	if(tmp_j < len)
		if(total[*i][tmp_j + 1] >= '!' && total[*i][tmp_j + 1] <= '/')
			return (1);
	if(*i >= 1 && tmp_j >= 1)
		if(total[*i - 1][tmp_j - 1] >= '!' && total[*i - 1][tmp_j - 1] <= '/')
			return (1);
	if(tmp_j < len && total[*i + 1] != NULL)
		if(total[*i + 1][tmp_j + 1] >= '!' && total[*i + 1][tmp_j + 1] <= '/')
			return (1);
	return (0);
}


int parse_engine_part(char **total, int *i)
{
    int tmp_j;
    int j;
	int symbol_seen;
	int nbr;
	int total_nbr;
	total_nbr = 0;
	nbr = 0;
	symbol_seen = 0;
    j = 0;
    tmp_j = 0;

	while(total[*i][tmp_j] != '\0')
	{
		while(total[*i][tmp_j] >= '0' && total[*i][tmp_j] <= '9')
		{
			if(tmp_j == 0)
				nbr = atoi(total[*i]);
			else if(!(total[*i][tmp_j - 1] >= '0' && total[*i][tmp_j - 1] <= '9'))
				nbr = atoi(total[*i]);
			symbol_seen = look_for_symbols(total, i, tmp_j);
			if(symbol_seen && tmp_j == strlen(total[*i]) - 1)
				total_nbr += nbr;
			else if(symbol_seen && !(total[*i][tmp_j + 1] >= '0' && total[*i][tmp_j + 1] <= '9'))
				total_nbr += nbr;
			tmp_j++;
		}
		tmp_j++;
	}
	return (total_nbr);
}

int main(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);

    char *totalstr[15000];
    char *next_line;
	fd = open(argv[1], O_RDONLY);
	next_line = (char *)1;


    int j;

    j = 0;
    totalstr[j] = (char *)1;
	while(1)
	{
        totalstr[j] = get_next_line(fd);
        if(totalstr[j] == NULL)
            break ;
        printf("%s strlen %d", totalstr[j], (int)strlen(totalstr[j]));
        j++;
	}
    printf("%s strlen \n\n", totalstr[j]);


    int total_engine_parts;
    total_engine_parts = 0;
    j = 0;
    while(totalstr[j] != NULL)
    {
        // if(totalstr[j] >= '0' && totalstr[j] <= '9')
            total_engine_parts += parse_engine_part(totalstr, &j);
        // else
            j++;
    }
	 printf("%d engineparts\n\n", total_engine_parts);
    j = 0;
    while(1)
    {
        if(totalstr[j] == NULL)
            break ;
        free(totalstr[j]);
        j++;
    }
    close(fd);
}