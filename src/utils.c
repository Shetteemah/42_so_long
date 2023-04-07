/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:09:31 by sheali            #+#    #+#             */
/*   Updated: 2023/04/05 19:42:40 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_position	*get_exit_position(char **map)
{
	t_position	*position;

	position = (t_position *)malloc(sizeof(t_position));
	position->x = -1;
	position->y = 0;
	while (map[++position->x][position->y] != 0)
	{
		while (map[position->x][position->y] != 0)
		{
			if (map[position->x][position->y] == 'E')
				return (position);
			position->y++;
		}
		position->y = 0;
	}
	return (NULL);
}

t_position	*get_player_position(char **map)
{
	t_position	*position;

	position = (t_position *)malloc(sizeof(t_position));
	position->x = -1;
	position->y = 0;
	while (map[++position->x][position->y] != 0)
	{
		while (map[position->x][position->y] != 0)
		{
			if (map[position->x][position->y] == 'P')
				return (position);
			position->y++;
		}
		position->y = 0;
	}
	return (NULL);
}

void	destroy_structure(t_map *map)
{
	free(map->moves[0]);
	free(map->moves[1]);
	free(map->moves[2]);
	free(map->moves[3]);
	free_string_array(map->map);
	free(map->exit);
	free(map);
}

t_map	*init_structure(char *map_string)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->moves[0] = (t_position *)malloc(sizeof(t_position));
	map->moves[1] = (t_position *)malloc(sizeof(t_position));
	map->moves[2] = (t_position *)malloc(sizeof(t_position));
	map->moves[3] = (t_position *)malloc(sizeof(t_position));
	map->moves[4] = NULL;
	map->lst_v = NULL;
	map->lst_vv = NULL;
	map->moves[0]->x = 0;
	map->moves[0]->y = -1;
	map->moves[1]->x = 0;
	map->moves[1]->y = 1;
	map->moves[2]->x = 1;
	map->moves[2]->y = 0;
	map->moves[3]->x = -1;
	map->moves[3]->y = 0;
	map->map = ft_split(map_string, '\n');
	map->player = get_player_position(map->map);
	map->exit = get_exit_position(map->map);
	map->map_loop = 0;
	return (map);
}

t_position	*get_component(char **map, char type)
{
	int			x;
	int			y;
	t_position	*exit;

	y = -1;
	exit = (t_position *)malloc(sizeof(t_position));
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == type)
			{
				exit->x = x;
				exit->y = y;
				return (exit);
			}
		}
	}
	return (NULL);
}
