
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>
# include "get_next_line.h"






//int parse_engine_part(char **total, int *i)
//{
//    int tmp_j;
//    int j;
//	int symbol_seen;
//	int nbr;
//	int total_nbr;
//	total_nbr = 0;
//	nbr = 0;
//	symbol_seen = 0;
//    j = 0;
//    tmp_j = 0;

//	while(total[*i][tmp_j] != '\0')
//	{
//		while(total[*i][tmp_j] >= '0' && total[*i][tmp_j] <= '9')
//		{
//			if(tmp_j == 0)
//				nbr = atoi(total[*i]);
//			else if(!(total[*i][tmp_j - 1] >= '0' && total[*i][tmp_j - 1] <= '9'))
//				nbr = atoi(total[*i]);
//			symbol_seen = look_for_symbols(total, i, tmp_j);
//			if(symbol_seen && tmp_j == strlen(total[*i]) - 1)
//				total_nbr += nbr;
//			else if(symbol_seen && !(total[*i][tmp_j + 1] >= '0' && total[*i][tmp_j + 1] <= '9'))
//				total_nbr += nbr;
//			tmp_j++;
//		}
//		tmp_j++;
//	}
//	return (total_nbr);
//}


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
	{
		return (1);
	}
	return (0);
}


int find_last_digit(char *next_line)
{
    int i;

    i = ft_strlen(next_line);
    while(i >= 0)
    {
        if(ft_isdigit(next_line[i]))
            return (next_line[i] - 48);
        i--;
    }
    return (0);
}

int find_first_digit(char *next_line)
{
    int i;

    i = 0;
    while(next_line[i])
    {
        if(ft_isdigit(next_line[i]))
            return (next_line[i] - 48);
        i++;
    }
    return (0);
}


int main(int argc, char **argv)
{
    int fd;
    int first;
    int last;
    int cali_sum;
    char *next_line;

    fd = open(argv[1], O_RDONLY);
    cali_sum = 0;
    first = 0;
    last = 0;
	while(1)
	{
        next_line = get_next_line(fd);
        if(next_line == NULL)
            break ;
        last = find_last_digit(next_line);
        first = find_first_digit(next_line);
        cali_sum += ((first * 10) + last);
        printf("%d + %d \t %d\n", first, last, first * 10 + last);
		free(next_line);
		next_line = 0;
	}
    printf("%d", cali_sum);
    //int total_engine_parts;
    //total_engine_parts = 0;
    //j = 0;
    //while(totalstr[j] != NULL)
    //{
    //    // if(totalstr[j] >= '0' && totalstr[j] <= '9')
    //        total_engine_parts += parse_engine_part(totalstr, &j);
    //    // else
    //        j++;
    //}
	// printf("%d engineparts\n\n", total_engine_parts);
    //j = 0;
    //while(1)
    //{
    //    if(totalstr[j] == NULL)
    //        break ;
    //    free(totalstr[j]);
    //    j++;
    //}
    close(fd);
}