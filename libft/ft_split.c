/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 03:24:11 by sheali            #+#    #+#             */
/*   Updated: 2023/04/03 08:13:30 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(const char *s, char c)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (s[i] != '\0'))
		{
			w++;
			while ((s[i] != c) && (s[i] != '\0'))
				i++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (w);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static void	*ft_free(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

static char	**ft_insert(char	**strii, char const *s, char c)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			len = ft_wordlen(&s[i], c);
			strii[j] = ft_substr(&s[i], 0, len);
			if (!strii[j])
			{
				return (ft_free(strii));
			}
			i += len;
			j++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (strii);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	words;

		if (!s)
		return (NULL);
	words = ft_wordcount(s, c);
	split = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!split)
		return (NULL);
	return (ft_insert(split, s, c));
}
