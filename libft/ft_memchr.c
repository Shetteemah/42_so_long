/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:17:51 by sheali            #+#    #+#             */
/*   Updated: 2022/04/24 01:22:35 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*search;
	size_t		i;

	search = (const char *)s;
	i = -1;
	while (++i < n)
	{
		if (*(search + i) == (char)c)
		{
			return ((void *)search + i);
		}
	}
	return (0);
}
