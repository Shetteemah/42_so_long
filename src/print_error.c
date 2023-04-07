/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:09:31 by sheali            #+#    #+#             */
/*   Updated: 2023/04/04 15:02:56 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_prints(int num)
{
	static const char	*errors[] = {A, B, C, D, E, F, G, H, I};

	if (num <= 0)
		return (0);
	write (2, errors[num - 1], ft_strlen(errors[num - 1]));
	return (TRUE);
}

int	print_sys_error(char errnum)
{
	if (!errnum)
		printf("Unknown error (%d)\n", errnum);
	else
		ft_putstr_fd(strerror(errnum), 2);
	write(2, "\n", 1);
	return (TRUE);
}
