/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:30:34 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/12/04 12:27:59 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int asc)
{
	while (*str >= 0)
	{
		if (*str == asc)
			return ((char *)str);
		if (!*str && *str == asc)
			return ((char *)str);
		if (!*str)
			break ;
		str++;
	}

	return (0);
}
