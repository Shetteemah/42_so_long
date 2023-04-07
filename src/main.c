/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:14:44 by sheali            #+#    #+#             */
/*   Updated: 2023/04/05 21:32:05 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_line(char **xy_map)
{
	int		i;

	i = 0;
	while (xy_map[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (error_prints(USAGE));
	else
	{
		if (map_has_errors(argv[1]) == TRUE)
			return (0);
		else
			start_game(argv[1]);
	}
	return (0);
}
