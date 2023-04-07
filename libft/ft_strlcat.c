/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:47 by sheali            #+#    #+#             */
/*   Updated: 2022/04/24 01:21:42 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src,
size_t dstsize)
{
	size_t		i;
	size_t		len;

	len = ft_strlen(dest) + ft_strlen((char *)src);
	if (dstsize <= ft_strlen(dest))
		return (ft_strlen((char *)src) + dstsize);
	while (*dest)
		dest++;
	i = 0;
	while ((i < dstsize - (len - ft_strlen((char *)src)) - 1) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}
