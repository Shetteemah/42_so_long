/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sqr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:09:31 by sheali            #+#    #+#             */
/*   Updated: 2023/04/05 21:31:02 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	delete_tile_textures(t_data **data)
{
	t_texture	*squares;

	squares = (*data)->squares;
	mlx_delete_texture(squares->floor);
	mlx_delete_texture(squares->wall);
	mlx_delete_texture(squares->exit[0]);
}

void	delete_idle_textures(t_data **data)
{
	t_move	*stand_still;

	stand_still = (*data)->stand_still;
	mlx_delete_texture(stand_still->right[0]);
	mlx_delete_texture(stand_still->right[1]);
	mlx_delete_texture(stand_still->right[2]);
	mlx_delete_texture(stand_still->right[3]);
}

void	destroy_movements(t_data **data)
{
	free((*data)->moves_p[0]);
	free((*data)->moves_p[1]);
	free((*data)->moves_p[2]);
	free((*data)->moves_p[3]);
}

void	destroy_idle_structure(t_data **data)
{
	t_move	*image;

	image = (*data)->stand_still;
	free(image);
}

void	destroy_tile_structure(t_data **data)
{
	t_texture	*image;

	image = (*data)->squares;
	free(image);
}
