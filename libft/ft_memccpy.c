/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:05:13 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/10 17:22:54 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char				*d;
	const	unsigned char		*s;
	unsigned	char			asc;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	asc = (unsigned char)c;
	while (len-- > 0)
	{
		*d++ = *s++;
		if (*s == asc)
		{
			*d = *s;
			dst = ++d;
			return (dst);
		}
	}
	return (0);
}
