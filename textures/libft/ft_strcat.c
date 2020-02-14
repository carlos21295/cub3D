/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:42:33 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/10 18:21:16 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	posd;
	int	poss;

	posd = 0;
	while (dest[posd] != '\0')
		posd++;
	poss = 0;
	while (src[poss] != '\0')
	{
		dest[posd + poss] = src[poss];
		poss++;
	}
	dest[posd + poss] = '\0';
	return (dest);
}
