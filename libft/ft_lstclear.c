/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:22:15 by sheali            #+#    #+#             */
/*   Updated: 2023/04/04 14:30:06 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

 void	ft_lstclear(t_list **lst, void (*del)(void*))
 {
 	t_list	*tmp;

 	if (!lst)
 		return ;
 	{
 		while (lst && *lst)
 		{
 			tmp = (*lst)->next;
 			ft_lstdelone(*lst, del);
 			(*lst) = tmp;
 		}
 	}
 }
