/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 04:29:09 by sheali            #+#    #+#             */
/*   Updated: 2023/04/04 13:24:29 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	forbidden_char(char c)
{
	if ((c == 'P' || c == 'C') || (c == 'E' || c == '0'))
		return (TRUE);
	else
		return (FALSE);
}

int	count_element(char *map, char c)
{
	unsigned long	i;
	int				count;

	i = 0;
	count = 0;
	while (i <= ft_strlen(map) - 1)
	{
		if (map[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	check_element(char *map)
{
	t_map	map_squares;

	map_squares.player_count = 0;
	map_squares.collectible_count = 0;
	map_squares.exit_count = 0;
	map_squares.player_count = count_element(map, 'P');
	map_squares.collectible_count = count_element(map, 'C');
	map_squares.exit_count = count_element(map, 'E');
	if (map_squares.player_count == 0 || map_squares.exit_count
		<= 0 || map_squares.collectible_count <= 0)
		return (FALSE);
	else
		return (TRUE);
}
