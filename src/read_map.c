/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:09:31 by sheali            #+#    #+#             */
/*   Updated: 2023/04/04 15:03:11 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*read_map_file(char *filename)
{
	int		fd;
	int		num_bytes;
	char	*map_buffer;

	num_bytes = get_map_size(filename) + 1;
	if (num_bytes <= 0)
		return (NULL);
	map_buffer = ft_calloc(sizeof(char), num_bytes);
	if (!map_buffer)
		return (NULL);
	fd = open(filename, O_RDONLY);
	read(fd, map_buffer, num_bytes);
	close(fd);
	return (map_buffer);
}
