/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 03:24:51 by sheali            #+#    #+#             */
/*   Updated: 2022/04/22 03:12:55 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_div(char *str, long int n, int len)
{
	while (len >= 0)
	{
		if (n < 0)
		{
			n = -1 * n;
		}
		str[len] = (char)(n % 10 + '0');
		n = n / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	len;
	int			i;

	len = n;
	i = ft_nbrlen(len);
	str = (char *) malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	str[i] = '\0';
	i--;
	str = ft_div(str, len, i);
	if (n < 0)
	{
		str[0] = '-';
		len = -1 * len;
	}
	return (str);
}
