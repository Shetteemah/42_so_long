/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:54:14 by sheali            #+#    #+#             */
/*   Updated: 2022/04/24 03:21:23 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	j;

	j = c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == j)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
