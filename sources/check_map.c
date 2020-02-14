/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 18:39:02 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/01/17 16:37:48 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_col(char **line)
{
	int		pos;
	int		cell;

	pos = 0;
	cell = 0;
	while ((*line)[pos])
	{
		if ((*line)[pos] != ' ')
			cell++;
		pos++;
	}
	return (cell);
}

static void	ft_cardinal(char **line, int *cell, t_game_params *g)
{
	int			pos;

	pos = 0;
	while ((*line)[pos])
	{
		if (ft_strchr("012NSWE", (*line)[pos]))
		{
			if ((*line)[pos] == 'N' || (*line)[pos] == 'S' ||
				(*line)[pos] == 'W' || (*line)[pos] == 'E')
			{
				g->init_dir = (*line)[pos];
				g->cardinal++;
				g->pos.x = g->row;
				g->pos.y = *cell;
			}
			(*cell)++;
		}
		pos++;
		pos += (*line)[pos] == ' ' ? 1 : 0;
	}
}

int			ft_check_line(char **line, int lt, t_game_params *g)
{
	int			pos;
	int			cell;

	pos = 0;
	cell = 0;
	ft_cardinal(line, &cell, g);
	if (g->col != ft_col(line))
		ft_exit_error("\nError\nWrong map format\n");
	if (g->row == 0 || !lt)
	{
		while ((*line)[pos])
		{
			if ((*line)[pos] != '1' && (*line)[pos] != ' ')
				ft_exit_error("\nError\nOpen map limits\n");
			pos++;
		}
	}
	else
	{
		if ((*line)[g->col] != '1' && (*line)[0] != '1')
			ft_exit_error("\nError\nOpen limits\n");
	}
	return (0);
}
