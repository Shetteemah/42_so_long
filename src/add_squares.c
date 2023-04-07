/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   add_squares.c	  :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: sheali <sheali@student.42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2022/11/09 23:09:31 by sheali	#+#	#+#	 */
/*   Updated: 2023/04/01 11:04:42 by sheali	   ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "../includes/so_long.h"

void	add_collectable_to_list(t_data **data, int x, int y)
{
	mlx_texture_t	*collectible_texture;
	mlx_image_t		*collectible_image;

	collectible_texture = mlx_load_png("texture/collectible.png");
	collectible_image = mlx_texture_to_image((*data)->mlx, collectible_texture);
	if ((*data)->maps[y][x] == 'C')
	{
		ft_lstadd_front(&((*data)->lst_c), ft_lstnew(collectible_image));
		((*data)->lst_c)->x = x;
		((*data)->lst_c)->y = y;
		mlx_image_to_window((*data)->mlx, ((*data)->lst_c)->position,
			x * SQUARES, y * SQUARES);
	}
	mlx_delete_texture(collectible_texture);
}

void	draw_floor(t_data **data, char c, int width, int height)
{
	t_texture	*textures;

	textures = (*data)->squares;
	if (c == '1')
		mlx_image_to_window((*data)->mlx, textures->wall_img, width, height);
	else
		mlx_image_to_window((*data)->mlx, textures->floor_img, width, height);
}

void	add_player_to_game(t_data **data)
{
	int			posx;
	int			posy;
	t_move		*player_move;
	t_position	*player_pos;

	player_pos = get_component((*data)->maps, 'P');
	posx = player_pos->x * SQUARES;
	posy = player_pos->y * SQUARES;
	player_move = (*data)->stand_still;
	mlx_image_to_window((*data)->mlx, player_move->still_right[0],
		posx - 24, posy - 12);
	free(player_pos);
}

void	add_exit(t_data **data)
{
	t_texture	*textures;
	t_position	*door_pos;

	door_pos = get_component((*data)->maps, 'E');
	textures = (*data)->squares;
	mlx_image_to_window((*data)->mlx, textures->exit_img[0],
		door_pos->x * SQUARES, door_pos->y * SQUARES);
	free(door_pos);
}
