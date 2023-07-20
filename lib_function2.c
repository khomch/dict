#include "functions_lib.h"

char	*ft_strchar(char *str, char to_find)
{
	int	i;
	int	k;
	int	count;

	i = 0;
	k = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == to_find)
		{
			count++;
			k = i;
		}
		if (count == 1)
			return (str + i);
		i++;
	}
	if (count == 1)
		return (str + k);
	return ((void *)0);
}

char	*store_zeros(char *str, int size)
{
	char	*buffer;
	int		i;

	buffer = (char *)malloc((size + 1) * sizeof(char));
	i = 0;
	while (i < size)
	{
		while (*str)
		{
			buffer[i] = *str;
			str++;
			i++;
		}
		buffer[i] = '0';
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_strdup(char	*src)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_is_spaced(char c)
{
	if ((c == ':') || (c == 32) || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
