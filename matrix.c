#include "functions_lib.h"

void	print_col_zero(int num, int dict_file, char *in_dict);
void	print_other_cols(int **matrix, int row, int dict_file, char *in_dict);
void	print_num(char *argv, int fd, char *indict);
int		row_sum(int *row);
int		g_is_first_printed;

void	create_matrix(int **matrix, char *argv)
{
	int		i;
	int		row;
	int		col;
	char	*rev_nums;
	char	*str_with_zeros;

	rev_nums = ft_strdup(argv);
	ft_strrev(rev_nums);
	str_with_zeros = store_zeros(rev_nums, 12);
	free(rev_nums);
	i = 0;
	g_is_first_printed = 0;
	while (i < 12)
	{
		row = i / 3;
		col = 2;
		matrix[row] = (int *)malloc(sizeof(int) * 3);
		while (col >= 0)
		{
			matrix[row][col] = str_with_zeros[i++] - 48;
			col--;
		}
	}
	free(str_with_zeros);
}

char	*ft_cinstr(char *str)
{
	while (*str)
	{
		if ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
		if (!((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')))
			str++;
		if (((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')))
			return (str);
	}
	return (str);
}

void	ft_print(char *end)
{
	char	*begin;
	char	*finish;

	begin = ft_cinstr(end);
	finish = ft_strchar(begin, '\n');
	if (g_is_first_printed)
		ft_putchar(' ');
	while (begin < finish)
		ft_putchar(*begin++);
	g_is_first_printed = 1;
}

void	handle_empty(int is_empty, int dict_file, char *in_dict)
{
	char	*str;

	if (is_empty)
	{
		str = ft_numtostr(0);
		print_num(str, dict_file, in_dict);
		free(str);
	}
}

void	print_matrix(int is_empty, int **matrix, int dict_file, char *in_dict)
{
	int		row;
	int		col;
	int		sum_of_row;

	row = 4;
	while (--row >= 0)
	{
		sum_of_row = row_sum(matrix[row]);
		col = -1;
		if (sum_of_row)
		{
			is_empty = 0;
			while (++col < 3 && sum_of_row)
			{
				if (col == 0 && sum_of_row > 99)
					print_col_zero(matrix[row][col], dict_file, in_dict);
				else if (col == 1)
				{
					print_other_cols(matrix, row, dict_file, in_dict);
					col++;
				}
			}
		}
	}
	handle_empty(is_empty, dict_file, in_dict);
}
