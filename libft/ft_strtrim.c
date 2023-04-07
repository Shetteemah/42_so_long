/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 03:23:39 by sheali            #+#    #+#             */
/*   Updated: 2022/04/21 01:41:56 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_content(char const c, char const *contain)
{
	size_t	i;

	i = 0;
	while (contain[i])
	{
		if (c == contain[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_beginning(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;

	i = 0;
	start = 0;
	while (ft_content(s1[i], set) == 1)
	{
		start += 1;
		i++;
	}
	return (start);
}

static size_t	ft_end(char const *s1, char const *set, size_t start)
{
	size_t	j;
	size_t	end;
	size_t	last;

	j = 0;
	end = 0;
	last = (ft_strlen(s1) - j);
	while (ft_content(s1[ft_strlen(s1) - 1 - j], set) && (start < last) == 1)
	{
		end += 1;
		j++;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (!s1)
		return (NULL);
	start = ft_beginning(s1, set);
	end = ft_end(s1, set, start);
	result = malloc(sizeof(char) * (ft_strlen(s1) - start - end + 1));
	if (result == NULL)
		return (NULL);
	result = ft_memcpy(result, s1 + start, ft_strlen(s1) - start - end);
	result[ft_strlen(s1) - start - end] = '\0';
	return (result);
}
