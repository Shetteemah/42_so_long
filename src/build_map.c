/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:09:31 by sheali            #+#    #+#             */
/*   Updated: 2023/04/04 14:15:46 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	add_player_container(t_data **data)
{
	t_position	*player_pos;
	int			pos_x;
	int			pos_y;

	player_pos = get_component((*data)->maps, 'P');
	pos_x = player_pos->x * SQUARES;
	pos_y = player_pos->y * SQUARES;
	(*data)->container_p = mlx_new_image((*data)->mlx, SQUARES, SQUARES);
	ft_memset((*data)->container_p->pixels, 0, SQUARES * SQUARES * 4);
	mlx_image_to_window((*data)->mlx, (*data)->container_p, pos_x, pos_y);
	free(player_pos);
}

void	draw_collectables(t_data **data)
{
	int	y;
	int	x;

	y = -1;
	while ((*data)->maps[++y])
	{
		x = -1;
		while ((*data)->maps[y][++x])
			add_collectable_to_list(data, x, y);
	}
}

void	draw_squares(t_data **data)
{
	int	y;
	int	x;

	y = -1;
	while ((*data)->maps[++y])
	{
		x = -1;
		while ((*data)->maps[y][++x])
			draw_floor(data, (*data)->maps[y][x], x * SQUARES, y * SQUARES);
	}
}

void	buildmap(t_data **data)
{
	int	w;
	int	h;

	w = (*data)->width;
	h = (*data)->height;
	init_move_texture(data);
	init_tile_textures(data);
	ft_memset((*data)->image->pixels, 255, w * h * 4);
	mlx_image_to_window((*data)->mlx, (*data)->image, 0, 0);
	draw_squares(data);
	draw_collectables(data);
	add_exit(data);
	add_player_container(data);
	add_player_to_game(data);
}
