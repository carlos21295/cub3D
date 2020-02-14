/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:03:34 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/12/08 14:57:26 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(char **gnl, char **line, int bt)
{
	char	*nl;
	char	*aux;

	if (bt < 0)
		return (-1);
	if (!bt && !*gnl)
	{
		*line = ft_strdup("");
		return (0);
	}
	else if ((nl = ft_strchr(*gnl, '\n')))
	{
		*nl = 0;
		*line = ft_strdup(*gnl);
		aux = ft_strdup(++nl);
		free(*gnl);
		*gnl = aux;
	}
	else
	{
		*line = *gnl;
		*gnl = NULL;
		return (0);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	int				bt;
	char			buff[BUFFER_SIZE + 1];
	static char		*gnl[4096];
	char			*aux;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((bt = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[bt] = 0;
		if (!gnl[fd])
			gnl[fd] = ft_strdup(buff);
		else
		{
			aux = ft_strjoin(gnl[fd], buff);
			free(gnl[fd]);
			gnl[fd] = aux;
		}
		if (ft_strchr(gnl[fd], '\n'))
			break ;
	}
	return (check(&gnl[fd], line, bt));
}
