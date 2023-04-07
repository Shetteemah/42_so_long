/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:09:31 by sheali            #+#    #+#             */
/*   Updated: 2023/04/06 21:28:15 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	element_is_forbidden(char *map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		if (map[i] != 'P' && map[i] != 'C' && map[i] != 'E' && map[i] != '0'
			&& map[i] != '1' && map[i] != '\n' && map[i] != '\0')
			return (TRUE);
		i++;
	}
	return (FALSE);
}
