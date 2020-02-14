/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:31:23 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/12 13:13:30 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	int		pos;

	if (str)
	{
		pos = 0;
		while (*(str + pos))
		{
			ft_putchar_fd(*(str + pos), fd);
			pos++;
		}
		ft_putchar_fd('\n', fd);
	}
}
