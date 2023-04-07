/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:09:31 by sheali            #+#    #+#             */
/*   Updated: 2023/04/05 21:23:37 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_collectible(char *map)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == 'C')
		count++;
		i++;
	}
	return (count);
}

void	mlx_delete_image_and_free(mlx_t *mlx, t_list *head)
{
	mlx_delete_image(mlx, head->position);
	free(head);
}

void	remove_collectible_list(t_data **data)
{
	t_list	*head;
	t_list	*temp;
	int		pos_x;
	int		pos_y;

	pos_x = (*data)->container_p->instances[0].x / SQUARES;
	pos_y = (*data)->container_p->instances[0].y / SQUARES;
	head = (*data)->lst_c;
	if (head->x == pos_x && head->y == pos_y)
	{
		(*data)->lst_c = (*data)->lst_c->next;
		mlx_delete_image_and_free((*data)->mlx, head);
		return ;
	}
	while (head->next)
	{
		if (head->next->x == pos_x && head->next->y == pos_y)
		{
			temp = head->next->next;
			free_n_remove_img_node(data, head->next->position, head);
			head->next = temp;
			return ;
		}
		head = head->next;
	}
}

void	collected_by_player(t_data **data)
{
	mlx_instance_t	*player;
	int				pos_x;
	int				pos_y;

	player = (*data)->container_p->instances;
	pos_x = player[0].x / SQUARES;
	pos_y = player[0].y / SQUARES;
	if ((*data)->maps[pos_y][pos_x] == 'C')
	{
		(*data)->maps[pos_y][pos_x] = '0';
		remove_collectible_list(data);
	}
}

void	all_collectibles_collected(t_data *data)
{
	mlx_image_t	*exit;

	if (!data->lst_c)
	{
		exit = data->squares->exit_img[0];
		ft_memcpy(exit->pixels,
			exit->pixels, SQUARES * SQUARES * 4);
	}
}
