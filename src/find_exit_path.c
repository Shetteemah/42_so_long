/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exit_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:02:01 by sheali            #+#    #+#             */
/*   Updated: 2023/04/05 21:06:15 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	not_visited(t_position *position, t_list *visited_list)
{
	t_list		*cursor;
	t_position	*list_pos;

	if (!visited_list)
		return (FALSE);
	cursor = visited_list;
	list_pos = visited_list->position;
	while (cursor)
	{
		list_pos = cursor->position;
		if (list_pos->x == position->x && list_pos->y == position->y)
			return (TRUE);
		cursor = cursor->next;
	}
	return (FALSE);
}

int	position_is_valid(t_position position, t_map **map)
{
	if ((not_visited(&position, (*map)->lst_v)) == FALSE
		&& (not_visited(&position, (*map)->lst_vv) == FALSE))
	{
		if ((((*map)->map[position.x][position.y]) != '1')
		&& ((*map)->map[position.x][position.y]))
		{
			return (TRUE);
		}
	}
	return (FALSE);
}

t_position	get_new_position(t_position *player, t_position *movement)
{
	t_position	position;

	position.x = player->x + movement->x;
	position.y = player->y + movement->y;
	return (position);
}

int	contains_component(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] && map[i][j])
	{
		while (map[i][j])
		{
			if (forbidden_char(map[i][j]) && map[i][j] != '\0')
			{
				return (TRUE);
			}
			j++;
		}
	j = 0;
	i++;
	}
	return (FALSE);
}

int	has_no_valid_path(t_map *map)
{
	check_map_path(map);
	ft_lstclear(&map->lst_vv, free);
	if (contains_component(map->map) == TRUE)
		return (TRUE);
	return (FALSE);
}
