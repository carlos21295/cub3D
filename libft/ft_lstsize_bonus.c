/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 12:39:37 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/12 15:31:00 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*aux;

	size = 0;
	aux = lst;
	if (aux)
		size++;
	else
		return (0);
	while (aux->next)
	{
		size++;
		aux = aux->next;
	}
	return (size);
}
