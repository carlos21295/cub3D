/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:58:00 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/10 17:24:37 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str, const void *ptr, size_t len)
{
	unsigned char	*s;
	unsigned char	*p;
	int				result;

	s = (unsigned char *)str;
	p = (unsigned char *)ptr;
	while (len-- > 0)
	{
		result = *s++ - *p++;
		if (result != 0)
			return (result);
	}
	return (0);
}
