/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 02:45:57 by sheali            #+#    #+#             */
/*   Updated: 2023/04/05 21:08:47 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_map_size(char *map)
{
	char	*buffer;
	int		total_bytes;
	int		byte_chunks;
	int		fd;

	fd = open(map, O_RDONLY);
	total_bytes = 0;
	buffer = malloc (sizeof(int) * 1024);
	byte_chunks = read(fd, buffer, 1024);
	if (!(byte_chunks))
	{
		free (buffer);
		close(fd);
		return (0);
	}
	total_bytes = total_bytes + byte_chunks;
	if (byte_chunks != '\0')
	{
		byte_chunks = read(fd, buffer, 1024);
		total_bytes = total_bytes + byte_chunks;
	}
	close(fd);
	free (buffer);
	return (total_bytes);
}

char	*print_map(char *map)
{
	char	*str;
	int		total_bytes;
	int		fd;

	total_bytes = (get_map_size(map) + 1);
	str = (char *)malloc(sizeof(char) * total_bytes);
	if (!str)
		return (NULL);
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		free(str);
		return (NULL);
	}
	if (read(fd, str, total_bytes) == -1)
	{
		free(str);
		close(fd);
		return (NULL);
	}
	str[total_bytes - 1] = 0;
	close(fd);
	return (str);
}

int	free_and_return_error(char *string, int flag)
{
	free(string);
	return (flag);
}

int	destroy_and_return_error(t_map *structure, int flag)
{
	destroy_structure(structure);
	return (flag);
}

int	map_has_errors(char *argv)
{
	char	*map_string;
	t_map	*map;

	map = NULL;
	if (invalid_file_path(argv))
		return (TRUE);
	map_string = read_map_file(argv);
	if (element_is_forbidden(map_string))
		return (error_prints(free_and_return_error(map_string, FRBDN_CHAR)));
	if (!map_string || map_string[0] == 0)
		return (error_prints(free_and_return_error(map_string, EMPTY_MAP)));
	if (!check_element(map_string))
		return (error_prints(free_and_return_error(map_string, MISSEN_COMP)));
	if (check_shape(map_string))
		return (error_prints(free_and_return_error(map_string, MAP_STRUCT)));
	if (check_border_tb(argv) || check_border_lr(argv))
		return (error_prints(free_and_return_error(map_string, MAP_STRUCT)));
	map = init_structure(map_string);
	free(map_string);
	if (has_no_valid_path(map))
		return (error_prints(destroy_and_return_error(map, MAP_PATH)));
	destroy_structure(map);
	return (FALSE);
}
