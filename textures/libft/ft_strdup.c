/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 10:29:48 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/10 16:49:48 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest != 0)
		return (ft_strcpy(dest, src));
	return (dest);
}
