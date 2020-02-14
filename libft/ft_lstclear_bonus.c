/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:42:58 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/12 15:21:45 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	while ((*lst)->next)
	{
		aux = (*lst);
		*lst = (*lst)->next;
		ft_lstdelone(aux, del);
	}
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
