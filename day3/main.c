
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>
# include "get_next_line.h"

int ifnum(char chr)
{
	if(chr >= '0' && chr <= '9')
		return (1);
	return (0);
}

int ifsymb(char chr)
{
	if(chr == '.')
		return (0);
	if(chr >= '!' && chr <= '/')
		return (1);
	if(chr >= ':' && chr <= '@')
		return (1);
	return (0);
}

int look_for_symbols(char **total, int *i, int tmp_j)
{
	int len = strlen(total[*i]);
	//onder
	if(total[*i + 1] != NULL)
		if(ifsymb(total[*i + 1][tmp_j]))
			return (1);
	//boven
	if(*i >= 1)
		if(ifsymb(total[(*i) - 1][tmp_j]))
			return (1);
	//links
	if(tmp_j >= 1)
		if(ifsymb(total[*i][tmp_j - 1]))
			return (1);
	//rechts
	if(tmp_j < len)
		if(ifsymb(total[*i][tmp_j + 1]))
			return (1);
	//linksonder
	if(tmp_j >= 1 && total[*i + 1] != NULL)
		if(ifsymb(total[*i + 1][tmp_j - 1]))
			return (1);
	//linksboven
	if(*i >= 1 && tmp_j >= 1)
		if(ifsymb(total[*i - 1][tmp_j - 1]))
			return (1);
	//rechtsonder
	if(tmp_j < len && total[*i + 1] != NULL)
		if(ifsymb(total[*i + 1][tmp_j + 1]))
			return (1);
	//rechtsboven
	if(tmp_j < len && *i >= 1)
		if(ifsymb(total[*i - 1][tmp_j + 1]))
			return (1);

	return (0);
}

int parse_engine_part(char **total, int *i)
{
    int tmp_j;
	int symbol_seen;
	int nbr;
	int total_nbr;

	total_nbr = 0;
	nbr = 0;
	symbol_seen = 0;
    tmp_j = 0;
	while(total[*i][tmp_j] != '\0')
	{
		while(total[*i][tmp_j] >= '0' && total[*i][tmp_j] <= '9')
		{
			if(tmp_j == 0)
				nbr = atoi(&total[*i][tmp_j]);
			else if(!(total[*i][tmp_j - 1] >= '0' && total[*i][tmp_j - 1] <= '9'))
				nbr = atoi(&total[*i][tmp_j]);
			if(!symbol_seen)
				symbol_seen = look_for_symbols(total, i, tmp_j);
			look_for_symbols(total, i, tmp_j);
			tmp_j++;
		}
		if(symbol_seen)
			printf("%d symbol? %d \n", nbr, symbol_seen);
		if(!symbol_seen)
			nbr = 0;
		total_nbr += nbr;
		nbr = 0;
		symbol_seen = 0;
		tmp_j++;
	}
	return (total_nbr);
}
// printf("%d symbol? %d \n", nbr, symbol_seen);


typedef struct p
{
	int parts_cnt;
} point;

int main(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    char *totalstr[15000];
	point *totalstr_cnt[15000];
    char *next_line;
	fd = open(argv[1], O_RDONLY);
	next_line = (char *)1;
    int j;

    j = 0;
    totalstr[j] = (char *)1;
	while(1)
	{
        totalstr[j] = get_next_line(fd);
		// totalstr_cnt[j] = calloc(sizeof(point), strlen(totalstr[j]));
        if(totalstr[j] == NULL)
            break ;
        // printf("%s strlen %d", totalstr[j], (int)strlen(totalstr[j]));
        j++;
	}
    // printf("%s strlen \n\n", totalstr[j]);
    int total_engine_parts;
    total_engine_parts = 0;
    j = 0;
    while(totalstr[j] != NULL)
    {
            total_engine_parts += parse_engine_part(totalstr, &j);
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