/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:43:53 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/10 17:24:36 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	asc;

	s = (unsigned char *)str;
	asc = (unsigned char)c;
	while (n-- > 0)
	{
		if (*s++ == asc)
		{
			str = s--;
			return (s);
		}
	}
	return (0);
}
