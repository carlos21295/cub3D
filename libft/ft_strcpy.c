/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:28:58 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/10 16:51:35 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int		ncounter;

	ncounter = 0;
	while (src[ncounter] != '\0')
	{
		dest[ncounter] = src[ncounter];
		ncounter++;
	}
	dest[ncounter] = '\0';
	return (dest);
}
