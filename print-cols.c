/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print-cols.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhomche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 22:05:28 by akhomche          #+#    #+#             */
/*   Updated: 2023/06/25 22:09:02 by akhomche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_lib.h"

void	print_col_zero(int num, int dict_file, char *in_dict)
{
	char	*str;
	char	*str2;

	if (num != 0)
	{
		str = ft_numtostr(num);
		str2 = ft_numtostr(100);
		print_num(str, dict_file, in_dict);
		print_num(str2, dict_file, in_dict);
		free(str);
		free(str2);
	}
}

void	print_to_20(int **matrix, int row, int dict_file, char *in_dict)
{
	long	num;
	char	*str;

	num = matrix[row][1] * 10 + matrix[row][2];
	str = ft_numtostr(num);
	print_num(str, dict_file, in_dict);
	free(str);
}

void	print_starting_20(int **matrix, int row, int dict_file, char *in_dict)
{
	char	*str;
	char	*str2;

	str = ft_numtostr(matrix[row][1] * 10);
	str2 = ft_numtostr(matrix[row][2]);
	print_num(str, dict_file, in_dict);
	print_num(str2, dict_file, in_dict);
	free(str2);
	free(str);
}

void	print_other_cols(int **matrix, int row, int dict_file, char *in_dict)
{
	char	*str;

	if ((matrix[row][1] * 10 + matrix[row][2]) > 0
		&& (matrix[row][1] * 10 + matrix[row][2]) < 21)
	{
		print_to_20(matrix, row, dict_file, in_dict);
	}
	if ((matrix[row][1] * 10 + matrix[row][2]) > 20)
	{
		print_starting_20(matrix, row, dict_file, in_dict);
	}
	if (row_sum(matrix[row]) && row != 0)
	{
		str = ft_numtostr(ft_power(1000, row));
		print_num(str, dict_file, in_dict);
		free(str);
	}
}
