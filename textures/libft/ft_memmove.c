/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:17:40 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/10 17:23:33 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char				*d;
	const	char		*s;
	char				*max_d;
	char				*max_s;

	if (dst || src)
	{
		d = dst;
		s = src;
		max_d = d + (len - 1);
		max_s = (char *)s + (len - 1);
		if (d < s)
		{
			while (len-- > 0)
				*d++ = *s++;
		}
		else
		{
			while (len-- > 0)
				*max_d-- = *max_s--;
		}
		return (dst);
	}
	return (NULL);
}
