/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:08:17 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/12 15:28:37 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*begin;
	t_list	*aux;

	if (lst || del)
	{
		aux = lst;
		if (!(begin = ft_lstnew(f(aux->content))))
			return (NULL);
		aux = aux->next;
		while (aux)
		{
			if (!(new = ft_lstnew(f(aux->content))))
				return (NULL);
			ft_lstadd_back(&begin, new);
			aux = aux->next;
		}
		return (begin);
	}
	return (NULL);
}
