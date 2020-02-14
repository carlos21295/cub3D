/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:52:30 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/12 15:33:03 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char				*sub_str;

	if (str)
	{
		if (!(sub_str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		ft_bzero(sub_str, len + 1);
		if (start < ft_strlen(str))
			ft_strlcpy(sub_str, str + start, len + 1);
		return (sub_str);
	}
	return (NULL);
}
