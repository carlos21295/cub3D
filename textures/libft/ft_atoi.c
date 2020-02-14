/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:03:32 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/10 17:59:01 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		intconv(const char *str, int pos, int cminus)
{
	unsigned int	number;

	number = 0;
	while (str[pos] > 47 && str[pos] < 58)
	{
		if ((number == 214748364 && cminus == 0 && str[pos] > '7') ||
			(number > 214748364 && cminus == 0))
			return (-1);
		else if ((number == 214748364 && cminus == 1 && str[pos] > '8') ||
				(number > 214748364 && cminus == 1))
			return (0);
		number = number * 10 + (str[pos] - '0');
		pos++;
	}
	if (cminus % 2 != 0)
		number = number * (-1);
	return ((int)number);
}

int				ft_atoi(const char *str)
{
	unsigned int	pos;
	int				cminus;

	pos = 0;
	while (str[pos] == 32 || str[pos] == '\t' || str[pos] == '\n' ||
				str[pos] == '\v' || str[pos] == '\f' || str[pos] == '\r')
		pos++;
	cminus = 0;
	if (str[pos] == 43 || str[pos] == 45)
	{
		if (str[pos] == 45)
			cminus++;
		pos++;
	}
	return (intconv(str, pos, cminus));
}
