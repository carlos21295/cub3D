/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:13:27 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/10 15:56:51 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	int		pos;

	if (str)
	{
		pos = 0;
		while (*(str + pos) != 0)
		{
			write(fd, &str[pos], 1);
			pos++;
		}
	}
}
