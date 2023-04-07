/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 03:22:55 by sheali            #+#    #+#             */
/*   Updated: 2022/04/24 01:21:53 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnew(size_t size)
{
	char	*str;

	if (size == 0)
		return (NULL);
	str = (char *) malloc(sizeof(char) * size);
	if (!(str))
	{
		return (0);
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = ft_strnew(ft_strlen(s1) + ft_strlen(s2)+ 1);
	if (!(result))
		return (NULL);
	ft_strlcat(ft_memcpy(result, s1, ft_strlen(s1) +1), s2, ft_strlen(s1)
		+ ft_strlen(s2)+ 1);
	return (result);
}
