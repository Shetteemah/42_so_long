/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squares.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/119 23:09:31 by sheali            #+#    #+#             */
/*   Updated: 20233/30 12:10:15 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_idle_images(t_data **data)
{
	t_move	*idle;

	idle = (*data)->stand_still;
	idle->still_right[0] = mlx_texture_to_image((*data)->mlx, idle->right[0]);
	idle->still_right[1] = mlx_texture_to_image((*data)->mlx, idle->right[1]);
	idle->still_right[2] = mlx_texture_to_image((*data)->mlx, idle->right[2]);
	idle->still_right[3] = mlx_texture_to_image((*data)->mlx, idle->right[3]);
	idle->still_right[4] = NULL;
	idle->stand_still = mlx_texture_to_image((*data)->mlx, idle->right[0]);
}

void	load_tile_images(t_data **data)
{
	t_texture	*squares;
	mlx_t		*mlx;

	mlx = (*data)->mlx;
	squares = (*data)->squares;
	squares->floor_img = mlx_texture_to_image(mlx, squares->floor);
	squares->wall_img = mlx_texture_to_image(mlx, squares->wall);
	squares->exit_img[0] = mlx_texture_to_image(mlx, squares->exit[0]);
	squares->exit_img[1] = NULL;
}

void	init_tile_textures(t_data **data)
{
	t_texture	*squares;

	(*data)->squares = (t_texture *)malloc(sizeof(t_texture));
	squares = (*data)->squares;
	squares->floor = mlx_load_png("texture/floor.png");
	squares->wall = mlx_load_png("texture/wall.png");
	squares->exit[0] = mlx_load_png("texture/exit.png");
	squares->exit[1] = NULL;
	load_tile_images(data);
	delete_tile_textures(data);
}

void	init_move_texture(t_data **data)
{
	t_move	*idle;

	(*data)->stand_still = (t_move *)malloc(sizeof(t_move));
	idle = (*data)->stand_still;
	idle->right[0] = mlx_load_png("texture/shark_right1.png");
	idle->right[1] = mlx_load_png("texture/shark_right2.png");
	idle->right[2] = mlx_load_png("texture/shark_right3.png");
	idle->right[3] = mlx_load_png("texture/shark_right4.png");
	idle->right[4] = NULL;
	load_idle_images(data);
	delete_idle_textures(data);
}
