/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:35:10 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/10 17:23:27 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (dst || src)
	{
		d = dst;
		s = src;
		while (len-- > 0)
			*d++ = *s++;
		return (dst);
	}
	return (NULL);
}
