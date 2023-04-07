/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eject.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:09:31 by sheali            #+#    #+#             */
/*   Updated: 2023/04/05 20:47:59 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_n_remove_img_node(t_data **data, mlx_image_t
*img, t_list *list_head)
{
	t_list	*node_to_remove;

	node_to_remove = list_head->next;
	mlx_delete_image((*data)->mlx, img);
	free(node_to_remove);
}

void	free_string_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_game_data(t_data **data)
{
	free_string_array((*data)->maps);
	free((*data)->map);
	destroy_movements(data);
	destroy_idle_structure(data);
	destroy_tile_structure(data);
	free((*data));
}
