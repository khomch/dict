/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print-matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhomche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 20:57:36 by akhomche          #+#    #+#             */
/*   Updated: 2023/06/25 22:09:20 by akhomche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_lib.h"

int	row_sum(int *row)
{
	return ((row[0] * 100) + (row[1] * 10) + row[2]);
}

void	print_num(char *argv, int fd, char *indict)
{
	char	*end;
	int		i;

	i = 0;
	indict = (char *)malloc(2000);
	if (!(indict))
		return ;
	fd = open("numbers.dict", O_RDONLY);
	if ((fd) == -1)
	{
		ft_putstr("Dict Error");
		return ;
	}
	while ((read(fd, &indict[i], 1)))
		i++;
	if (close(fd) == -1)
	{
		ft_putstr("Close Error");
		return ;
	}
	end = ft_strstr(indict, argv);
	if (end == 0)
		return ;
	ft_print(end);
	free(indict);
}
