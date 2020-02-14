/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:44:12 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/01/18 13:58:03 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_cardinal_movement(t_game_params *g)
{
	if (g->key.up == 1)
		ft_key_d(g->dir.x, g->dir.y, g);
	else if (g->key.down == 1)
		ft_key_d(-g->dir.x, -g->dir.y, g);
	else if (g->key.strafe_r == 1)
		ft_key_d(g->dir.y, -g->dir.x, g);
	else if (g->key.strafe_l == 1)
		ft_key_d(-g->dir.y, g->dir.x, g);
}

int		ft_diagonal_movement(t_game_params *g)
{
	if (g->key.up == 1 && g->key.strafe_r == 1)
	{
		ft_key_d(g->dir.x + g->dir.y, -g->dir.x + g->dir.y, g);
		return (1);
	}
	else if (g->key.up == 1 && g->key.strafe_l == 1)
	{
		ft_key_d(g->dir.x - g->dir.y, g->dir.x + g->dir.y, g);
		return (1);
	}
	else if (g->key.down == 1 && g->key.strafe_r == 1)
	{
		ft_key_d(-g->dir.x + g->dir.y, -g->dir.y - g->dir.x, g);
		return (1);
	}
	else if (g->key.down == 1 && g->key.strafe_l == 1)
	{
		ft_key_d(-g->dir.x - g->dir.y, -g->dir.y + g->dir.x, g);
		return (1);
	}
	return (0);
}
