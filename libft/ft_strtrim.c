/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:32:30 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/11/12 16:38:55 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start(char const *str, char const *set)
{
	size_t		start;

	start = 0;
	while (*(str + start) != 0 && ft_strchr(set, (int)*(str + start)))
		start++;
	return (start);
}

static size_t	ft_end(char const *str, char const *set, size_t start)
{
	size_t	end;

	end = ft_strlen(str);
	while (end > start && ft_strchr(set, (int)*(str + end)))
		end--;
	return (end);
}

char			*ft_strtrim(char const *str, char const *set)
{
	char		*trim;
	size_t		start;
	size_t		end;
	int			pos;

	if (!str)
		return (NULL);
	start = ft_start(str, set);
	end = ft_end(str, set, start);
	if (!end)
	{
		trim = malloc(1);
		*trim = 0;
		return (trim);
	}
	if (!(trim = (char *)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	pos = 0;
	while (start++ <= end)
	{
		*(trim + pos) = *(str + start - 1);
		pos++;
	}
	*(trim + pos) = 0;
	return (trim);
}
