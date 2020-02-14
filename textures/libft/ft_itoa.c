/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:50:44 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/12 16:46:03 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int				digit;
	unsigned int	x;
	char			*number;
	int				size;

	x = n < 0 ? -n : n;
	digit = n <= 0 ? 1 : 0;
	while (x > 0)
	{
		digit++;
		x = x / 10;
	}
	size = digit;
	if (!(number = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	x = n < 0 ? -n : n;
	*number = n < 0 ? '-' : 0;
	while (digit-- > 0 && *(number + digit) != '-')
	{
		*(number + digit) = x % 10 + '0';
		x = x / 10;
	}
	*(number + size) = 0;
	return (number);
}
