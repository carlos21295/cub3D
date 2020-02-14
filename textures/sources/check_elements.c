/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 18:48:00 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/01/18 15:45:42 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_color_format(char **line, int *pos)
{
	int color;

	color = (ft_atoi(&(*line)[*pos])) * 65536;
	while (ft_isdigit((*line)[*pos]))
		(*pos)++;
	if ((*line)[(*pos)++] != ',')
		ft_exit_error("\nError\nWrong floor format\n");
	color += (ft_atoi(&(*line)[*pos])) * 256;
	while (ft_isdigit((*line)[*pos]))
		(*pos)++;
	if ((*line)[(*pos)++] != ',')
		ft_exit_error("\nError\nWrong floor format\n");
	color += (ft_atoi(&(*line)[*pos]));
	while (ft_isdigit((*line)[*pos]))
		(*pos)++;
	if ((*line)[*pos] != 0)
		ft_exit_error("\nError\nWrong floor format\n");
	return (color);
}

static int	ft_resolution(char **line, t_game_params *g)
{
	int		pos;

	pos = 1;
	if ((*line)[pos++] != ' ')
		ft_exit_error("\nError\nWrong resolution format\n");
	while ((*line)[pos] == ' ')
		pos++;
	if (!(ft_isdigit((*line)[pos])))
		ft_exit_error("\nError\nWrong resolution format\n");
	g->window.x = ft_atoi(&(*line)[pos]);
	while (ft_isdigit((*line)[pos]))
		pos++;
	if ((*line)[pos++] != ' ')
		ft_exit_error("\nError\nWrong resolution format\n");
	while ((*line)[pos] == ' ')
		pos++;
	if (!(ft_isdigit((*line)[pos])))
		ft_exit_error("\nError\nWrong resolution format\n");
	g->window.y = ft_atoi(&(*line)[pos]);
	while (ft_isdigit((*line)[pos]))
		pos++;
	if ((*line)[pos] != 0)
		ft_exit_error("\nError\nWrong resolution format\n");
	return (1);
}

static int	ft_floor(char **line, t_game_params *g)
{
	int		pos;

	pos = 1;
	if ((*line)[pos++] != ' ')
		ft_exit_error("\nError\nWrong floor format\n");
	while ((*line)[pos] == ' ')
		pos++;
	if (ft_isdigit((*line)[pos]))
	{
		g->floor = ft_color_format(line, &pos);
		g->floor_path = NULL;
	}
	else if ((*line)[pos] == '.')
	{
		if (!(g->floor_path = ft_strdup(&(*line)[pos])))
			return (-1);
	}
	else
		ft_exit_error("\nError\nWrong floor format\n");
	return (1);
}

static int	ft_ceiling(char **line, t_game_params *g)
{
	int		pos;

	pos = 1;
	if ((*line)[pos++] != ' ')
		ft_exit_error("\nError\nWrong ceiling format\n");
	while ((*line)[pos] == ' ')
		pos++;
	if (ft_isdigit((*line)[pos]))
	{
		g->ceiling = ft_color_format(line, &pos);
		g->ceiling_path = NULL;
	}
	else if ((*line)[pos] == '.')
	{
		if (!(g->ceiling_path = ft_strdup(&(*line)[pos])))
			return (-1);
	}
	else
		ft_exit_error("\nError\nWrong ceiling format\n");
	return (1);
}

int			ft_elements(char **line, t_game_params *g)
{
	if (**line == 'R')
		return (ft_resolution(line, g));
	else if (**line == 'N' && *(*line + 1) == 'O')
		return (ft_no(line, g));
	else if (**line == 'S' && *(*line + 1) == 'O')
		return (ft_so(line, g));
	else if (**line == 'W' && *(*line + 1) == 'E')
		return (ft_we(line, g));
	else if (**line == 'E' && *(*line + 1) == 'A')
		return (ft_ea(line, g));
	else if (**line == 'S')
		return (ft_sprite(line, g));
	else if (**line == 'F')
		return (ft_floor(line, g));
	else if (**line == 'C')
		return (ft_ceiling(line, g));
	else if (!**line)
		return (0);
	else
	{
		ft_exit_error("\nError\nIncorrect parameters\n");
		return (-1);
	}
}
