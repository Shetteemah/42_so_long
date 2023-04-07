/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:35:37 by sheali            #+#    #+#             */
/*   Updated: 2022/04/24 01:19:23 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	total;
	int			negate;

	total = 0;
	negate = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negate = negate * -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		total = total * 10 + (*str - 48);
		str++;
		if (total * negate > 2147483647)
			return (-1);
		if (total * negate < -2147483648)
			return (0);
	}
	return ((int) total * negate);
}
