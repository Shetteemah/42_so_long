/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:02:01 by sheali            #+#    #+#             */
/*   Updated: 2023/04/04 14:59:25 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_player(t_position new_pos, t_map **map)
{
	t_position	*node;

	node = (t_position *)malloc(sizeof(t_position));
	node->x = (*map)->player->x;
	node->y = (*map)->player->y;
	ft_lstadd_front(&(*map)->lst_v, ft_lstnew(node));
	(*map)->player->x = new_pos.x;
	(*map)->player->y = new_pos.y;
	(*map)->map[(*map)->player->x][(*map)->player->y] = 'V';
	(*map)->moved_p = 1;
}

void	step_back(t_map **map)
{
	t_list		*temp;

	ft_lstadd_front(&(*map)->lst_vv, ft_lstnew((*map)->player));
	if (!(*map)->lst_v)
	{
		(*map)->map_loop = 1;
		return ;
	}
	temp = (*map)->lst_v;
	(*map)->player = (*map)->lst_v->position;
	(*map)->lst_v = (*map)->lst_v->next;
	temp->next = NULL;
	free(temp);
}

void	check_map_path(t_map *map)
{
	int			i;
	t_position	new_pos;

	i = 0;
	(map)->map[(map)->player->x][(map)->player->y] = 'V';
	(map)->moved_p = 1;
	while (map->map_loop == 0)
	{
		while (map->moves[i])
		{
			map->moved_p = 0;
			new_pos = get_new_position(map->player, map->moves[i++]);
			if (position_is_valid(new_pos, &map) == TRUE)
			{
				move_player(new_pos, &map);
				break ;
			}
		}
		if (!map->moved_p)
			step_back(&map);
		i = 0;
	}
}
