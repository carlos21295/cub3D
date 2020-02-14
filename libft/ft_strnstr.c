/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:07:56 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/12 09:47:54 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char				*h;
	char				*n;
	unsigned int		pos;
	unsigned int		bt;

	h = (char *)haystack;
	n = (char *)needle;
	pos = 0;
	bt = 0;
	if (*n == 0)
		return ((char *)haystack);
	while (bt < len && *(h + bt))
	{
		if (*(h + bt) == *n)
		{
			while (*(n + pos) == *(h + bt + pos) && *(n + pos) != 0
				&& pos + bt < len)
				pos++;
			if (*(n + pos) == 0)
				return ((h + bt));
		}
		bt++;
	}
	return (0);
}
