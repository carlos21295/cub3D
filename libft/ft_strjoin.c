/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:13:28 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/12 15:53:46 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str, char const *ptr)
{
	char	*new;
	int		s;
	int		p;

	if (!str)
		return (NULL);
	s = ft_strlen(str);
	p = ft_strlen(ptr);
	if (!(new = (char *)malloc(sizeof(char) * (s + p + 1))))
		return (NULL);
	s = 0;
	while (*(str + s))
	{
		*(new + s) = *(str + s);
		s++;
	}
	p = 0;
	while (*(ptr + p))
	{
		*(new + s + p) = *(ptr + p);
		p++;
	}
	*(new + s + p) = 0;
	return (new);
}
