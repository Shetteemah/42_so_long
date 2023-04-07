/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:09:31 by sheali            #+#    #+#             */
/*   Updated: 2023/04/05 21:30:28 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	player_is_on_exit(t_data **data)
{
	mlx_instance_t	*player_instance;
	mlx_instance_t	*exit_instance;

	player_instance = &(*data)->container_p->instances[0];
	exit_instance = &(*data)->squares->exit_img[0]->instances[0];
	if (player_instance->x == exit_instance->x
		&& player_instance->y == exit_instance->y)
		return (1);
	return (0);
}

void	animate_idle_player(void *param)
{
	t_data		*data;
	mlx_image_t	**player;
	static int	frames;
	static int	i;

	data = param;
	player = data->stand_still->still_right;
	if (frames == 0 || frames % 7 == 0)
	{
		ft_memcpy(player[0]->pixels, player[i]->pixels, IMG_W * IMG_H * 4);
		if (i == 7)
		{
			frames--;
			i--;
		}
		i++;
	}
	frames++;
}

int	movement_is_valid(t_data *data, t_position *position)
{
	mlx_instance_t	*player_instance;
	int				pos_x;
	int				pos_y;

	pos_x = position->x;
	pos_y = position->y;
	player_instance = data->container_p->instances;
	pos_x = pos_x + player_instance->x / SQUARES;
	pos_y = pos_y + player_instance->y / SQUARES;
	if (data->maps[pos_y][pos_x] != '1')
		return (1);
	return (0);
}

void	initialize_movements(t_data **data)
{
	(*data)->moves_p[0] = (t_position *)malloc(sizeof(t_position));
	(*data)->moves_p[1] = (t_position *)malloc(sizeof(t_position));
	(*data)->moves_p[2] = (t_position *)malloc(sizeof(t_position));
	(*data)->moves_p[3] = (t_position *)malloc(sizeof(t_position));
	(*data)->moves_p[4] = NULL;
	(*data)->moves_p[0]->x = 0;
	(*data)->moves_p[0]->y = -1;
	(*data)->moves_p[1]->x = 0;
	(*data)->moves_p[1]->y = 1;
	(*data)->moves_p[2]->x = 1;
	(*data)->moves_p[2]->y = 0;
	(*data)->moves_p[3]->x = -1;
	(*data)->moves_p[3]->y = 0;
}
