/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:36:29 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/12 09:36:16 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int asc)
{
	int		pos;

	pos = 0;
	while (*(str + pos))
		pos++;
	while (pos >= 0)
	{
		if (*(str + pos) == asc)
			return ((char *)(str + pos));
		pos--;
	}
	return (NULL);
}
