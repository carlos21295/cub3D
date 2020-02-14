/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:40:54 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/09 17:25:58 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int		posd;
	unsigned int		poss;

	posd = 0;
	poss = 0;
	while (dst[posd] != 0 && posd < dstsize)
		posd++;
	if (dst[posd] == 0)
	{
		while (poss + posd < (dstsize - 1) && src[poss] != '\0')
		{
			dst[posd + poss] = src[poss];
			poss++;
		}
		dst[posd + poss] = '\0';
	}
	while (src[poss] != '\0')
		poss++;
	return (posd + poss);
}
