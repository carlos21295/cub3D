/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:41:29 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/10 19:32:18 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	pos;

	if (!dest)
		return (size);
	if (size > 0)
	{
		pos = 0;
		while (pos < size - 1 && src[pos] != 0)
		{
			dest[pos] = src[pos];
			pos++;
		}
		dest[pos] = '\0';
	}
	return (ft_strlen(src));
}
