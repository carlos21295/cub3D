/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:32:58 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/05 16:50:00 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				result;
	unsigned char	*aux_s1;
	unsigned char	*aux_s2;

	aux_s1 = (unsigned char *)s1;
	aux_s2 = (unsigned char *)s2;
	while (n-- && (*aux_s1 != '\0' || *aux_s2 != '\0'))
	{
		result = *aux_s1++ - *aux_s2++;
		if (result != 0)
			return (result);
	}
	return (0);
}
