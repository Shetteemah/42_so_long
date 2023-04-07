/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 00:03:45 by sheali            #+#    #+#             */
/*   Updated: 2022/04/24 01:22:27 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*cdest;
	char			*csrc;
	unsigned int	i;

	cdest = (char *)dest;
	csrc = (char *)src;
	i = 0;
	if (cdest == csrc)
		return (cdest);
	if (csrc < cdest)
	{
		i = n;
		while (i--)
			((char *)cdest)[i] = ((char *)csrc)[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char *)cdest)[i] = ((char *)csrc)[i];
			i++;
		}
	}
	return (cdest);
}
