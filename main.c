/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhomche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:09:13 by akhomche          #+#    #+#             */
/*   Updated: 2023/06/24 13:37:28 by akhomche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_lib.h"

int	check_input(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	handle_print(char *argv, int dict_file, char *indict)
{
	int	**matrix;
	int	i;
	int	is_empty;

	is_empty = 1;
	i = 3;
	if (ft_strlen(argv) > 12)
	{
		ft_putstr("Dict Error\n");
		return ;
	}
	matrix = (int **)malloc(sizeof(int *) * (4));
	create_matrix(matrix, argv);
	print_matrix(is_empty, matrix, dict_file, indict);
	while (i >= 0)
	{
		free(matrix[i--]);
	}
	free(matrix);
}

int	main(int argc, char **argv)
{
	int		dict_file;
	char	*indict;

	if (argc == 1 || !ft_strlen(argv[1]))
	{
		ft_putstr("Argument required");
		return (0);
	}
	if (argc > 3)
		ft_putstr("Too many arguments");
	if (argc == 3)
		ft_putstr("Dict Error\n");
	else if (argc == 2)
	{
		indict = (char *)malloc(sizeof(char) * (400));
		dict_file = 0;
		if (check_input(argv[1]))
		{
			handle_print(argv[1], dict_file, indict);
			free(indict);
		}
		else
			ft_putstr("Invalid argument");
	}
	return (0);
}
