/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 04:29:09 by sheali            #+#    #+#             */
/*   Updated: 2023/04/05 21:25:10 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_shape(char *map)
{
	char	**map_sketch;
	size_t	reference;
	int		i;
	int		j;

	map_sketch = ft_split(map, '\n');
	reference = ft_strlen(map_sketch[0]);
	i = count_line(map_sketch);
	j = 0;
	while (j < i)
	{
		if (ft_strlen(map_sketch[j]) != reference)
		{
			free_string_array(map_sketch);
			return (TRUE);
		}
		j++;
	}
	free_string_array(map_sketch);
	return (0);
}

int	free_and_return(int flag, char **map)
{
	if (flag == TRUE)
	{
		free_string_array(map);
		return (TRUE);
	}
	free_string_array(map);
	return (FALSE);
}

int	check_border_tb(char *map)
{
	char	*str;
	char	**map_border;
	int		i;
	int		j;
	int		len;

	str = print_map(map);
	if (!str)
		return (1);
	i = 0;
	map_border = ft_split(str, '\n');
	free(str);
	j = count_line(map_border) - 1;
	len = (ft_strlen(map_border[i]));
	while (i < len)
	{
		if (map_border[0][i] != '1')
			return (free_and_return(TRUE, map_border));
		if (map_border[j][i] != '1')
			return (free_and_return(TRUE, map_border));
		i++;
	}
	return (free_and_return(FALSE, map_border));
}

int	check_border_lr(char *map)
{
	char	*str;
	char	**map_border;
	int		i;
	int		j;
	int		len;

	str = print_map(map);
	if (!str)
		return (FALSE);
	i = 0;
	j = -1;
	map_border = ft_split(str, '\n');
	free(str);
	len = (ft_strlen(map_border[i]));
	while (++j < count_line(map_border) - 1)
	{
		i = 0;
		while (i < len)
		{
			if (map_border[j][0] != '1' || map_border[j][len - 1] != '1')
				return (free_and_return(TRUE, map_border));
			i++;
		}
	}
	return (free_and_return(FALSE, map_border));
}

int	invalid_file_path(char *argv)
{
	int		fd;
	int		comp;

	fd = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	comp = strncmp((argv + (ft_strlen(argv) - 4)), ".ber\0", 5);
	if (comp != 0)
	{
		close(fd);
		return (error_prints(MAP_FORMAT));
	}
	close(fd);
	return (0);
}
