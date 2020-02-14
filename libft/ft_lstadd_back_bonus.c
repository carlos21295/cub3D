/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:08:06 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/12 15:19:09 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*aux;

	if (alst)
	{
		aux = *alst;
		if (!*alst)
		{
			*alst = new;
		}
		else
		{
			aux = ft_lstlast(*alst);
			aux->next = new;
		}
	}
}
