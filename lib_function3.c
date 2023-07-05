/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:12:15 by sabrifer          #+#    #+#             */
/*   Updated: 2023/06/25 15:58:27 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_lib.h"

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!to_find[i])
		return (str);
	while (str[i])
	{
		while (str[i + k] == to_find[k])
		{
			if ((to_find[k + 1] == '\0') && ft_is_spaced(str[i + k + 1]))
				return (str + i);
			k++;
		}
		k = 0;
		i++;
	}
	return ((void *)0);
}

int	ft_power(int nb, int power)
{
	int	res;

	res = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power)
	{
		res = res * nb;
		power--;
	}
	return (res);
}

char	*ft_numtostr(int num)
{
	int		i;
	int		j;
	int		n[16];
	char	*res;

	i = 0;
	j = 0;
	while (num)
	{
		n[i++] = num % 10;
		num /= 10;
	}
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	while (--i >= 0)
	{
		res[j++] = n[i] + 48;
	}
	res[j] = '\0';
	return (res);
}	
