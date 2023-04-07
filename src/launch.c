/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:14:44 by sheali            #+#    #+#             */
/*   Updated: 2023/04/06 21:16:06 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game_data(t_data **data, char *argv)
{
	int	width;
	int	height;

	(*data) = malloc(sizeof(t_data));
	(*data)->map = read_map_file(argv);
	(*data)->maps = ft_split((*data)->map, '\n');
	(*data)->width = SQUARES * ft_strlen(*(*data)->maps);
	(*data)->height = SQUARES * count_line((*data)->maps);
	width = (*data)->width;
	height = (*data)->height;
	(*data)->mlx = mlx_init(width, height, "so_long", true);
	(*data)->image = mlx_new_image((*data)->mlx, width, height);
	(*data)->lst_c = NULL;
	initialize_movements(data);
}

void	function_move(t_data *data, t_position *position)
{
	mlx_image_t		*player;
	mlx_image_t		*player_box;
	static int		move;

	player = data->stand_still->still_right[0];
	player_box = data->container_p;
	if (movement_is_valid(data, position))
	{
		player_box->instances[0].y += position->y * SQUARES;
		player_box->instances[0].x += position->x * SQUARES;
		player->instances[0].y += position->y * SQUARES;
		player->instances[0].x += position->x * SQUARES;
		move++;
		ft_putstr_fd("moves #: ", 1);
		ft_putnbr_fd(move, 1);
		write(1, "\n", 1);
	}
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_data			*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		function_move(data, data->moves_p[1]);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		function_move(data, data->moves_p[3]);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		function_move(data, data->moves_p[0]);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		function_move(data, data->moves_p[2]);
	if (player_is_on_exit(&data) && !data->lst_c)
	{
		ft_putstr_fd("Congratulations, you finished!!!", 1);
		write(1, "\n", 1);
		mlx_close_window(data->mlx);
	}
}

void	hook(void *param)
{
	t_data	*data;

	data = param;
	collected_by_player(&data);
	all_collectibles_collected(data);
}

void	start_game(char *argv)
{
	t_data	*data;

	init_game_data(&data, argv);
	buildmap(&data);
	mlx_key_hook(data->mlx, keyhook, data);
	mlx_loop_hook(data->mlx, hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	if (data->lst_c)
		ft_lstclear(&data->lst_c, NULL);
	free_game_data (&data);
}
