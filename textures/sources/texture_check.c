/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 18:34:17 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/01/18 16:06:57 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_no(char **line, t_game_params *g)
{
	int		pos;

	pos = 2;
	if ((*line)[pos++] != ' ')
		return (-1);
	while ((*line)[pos] == ' ')
		pos++;
	if (!(g->wall_path[NO] = ft_strdup(&(*line)[pos])))
		return (-1);
	return (1);
}

int	ft_so(char **line, t_game_params *g)
{
	int		pos;

	pos = 2;
	if ((*line)[pos++] != ' ')
		return (-1);
	while ((*line)[pos] == ' ')
		pos++;
	if (!(g->wall_path[SO] = ft_strdup(&(*line)[pos])))
		return (-1);
	return (1);
}

int	ft_we(char **line, t_game_params *g)
{
	int		pos;

	pos = 2;
	if ((*line)[pos++] != ' ')
		return (-1);
	while ((*line)[pos] == ' ')
		pos++;
	if (!(g->wall_path[WE] = ft_strdup(&(*line)[pos])))
		return (-1);
	return (1);
}

int	ft_ea(char **line, t_game_params *g)
{
	int		pos;

	pos = 2;
	if ((*line)[pos++] != ' ')
		return (-1);
	while ((*line)[pos] == ' ')
		pos++;
	if (!(g->wall_path[EA] = ft_strdup(&(*line)[pos])))
		return (-1);
	return (1);
}

int	ft_sprite(char **line, t_game_params *g)
{
	int		pos;

	pos = 1;
	if ((*line)[pos++] != ' ')
		return (-1);
	while ((*line)[pos] == ' ')
		pos++;
	if (!(g->sprite_path = ft_strdup(&(*line)[pos])))
		return (-1);
	return (1);
}
