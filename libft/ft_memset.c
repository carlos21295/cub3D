/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:27:12 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/10 15:43:48 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int asc, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (len-- > 0)
		*ptr++ = (unsigned char)asc;
	return (str);
}
