/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:06:53 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/12 13:38:45 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char			*fstr;
	unsigned int	pos;

	if (str && f)
	{
		pos = 0;
		if (!(fstr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
			return (NULL);
		while (*(str + pos))
		{
			*(fstr + pos) = f(pos, *(str + pos));
			pos++;
		}
		*(fstr + pos) = 0;
		return (fstr);
	}
	return (NULL);
}
