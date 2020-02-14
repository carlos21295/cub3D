/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 10:54:45 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/01/17 16:43:54 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_press(int key, t_game_params *g)
{
	if (key == 13)
		g->key.up = 1;
	if (key == 12)
		g->key.q = 1;
	if (key == 1)
		g->key.down = 1;
	if (key == 2)
		g->key.strafe_r = 1;
	if (key == 0)
		g->key.strafe_l = 1;
	if (key == 124)
		g->key.right = 1;
	if (key == 123)
		g->key.left = 1;
	if (key == 257)
		g->key.sprint = 1;
	if (key == 50)
		g->key.crouch = g->window.y / 15;
	if (key == 53)
		ft_exit();
	return (0);
}

int		ft_release(int key, t_game_params *g)
{
	if (key == 13)
		g->key.up = 0;
	if (key == 12)
		g->key.q = 0;
	if (key == 1)
		g->key.down = 0;
	if (key == 2)
		g->key.strafe_r = 0;
	if (key == 0)
		g->key.strafe_l = 0;
	if (key == 124)
		g->key.right = 0;
	if (key == 123)
		g->key.left = 0;
	if (key == 257)
		g->key.sprint = 0;
	if (key == 50)
		g->key.crouch = 0;
	return (0);
}

void	ft_key_d(double x, double y, t_game_params *g)
{
	if ((g->map[(int)(g->pos.x + x * (g->m_speed + 0.1))][(int)(g->pos.y)])
		!= 49)
		g->pos.x += x * g->m_speed;
	if ((g->map[(int)(g->pos.x)][(int)(g->pos.y + y * (g->m_speed + 0.1))])
		!= 49)
		g->pos.y += y * g->m_speed;
}

void	ft_key_right(t_game_params *g)
{
	double prv_dir_x;
	double prv_plane_x;

	prv_dir_x = g->dir.x;
	prv_plane_x = g->plane.x;
	g->dir.x = g->dir.x * cos(-g->r_speed) - g->dir.y * sin(-g->r_speed);
	g->dir.y = prv_dir_x * sin(-g->r_speed) + g->dir.y * cos(-g->r_speed);
	g->plane.x = g->plane.x * cos(-g->r_speed) - g->plane.y * sin(-g->r_speed);
	g->plane.y = prv_plane_x * sin(-g->r_speed) + g->plane.y * cos(-g->r_speed);
}

void	ft_key_left(t_game_params *g)
{
	double prv_dir_x;
	double prv_plane_x;

	prv_dir_x = g->dir.x;
	prv_plane_x = g->plane.x;
	g->dir.x = g->dir.x * cos(g->r_speed) - g->dir.y * sin(g->r_speed);
	g->dir.y = prv_dir_x * sin(g->r_speed) + g->dir.y * cos(g->r_speed);
	g->plane.x = g->plane.x * cos(g->r_speed) - g->plane.y * sin(g->r_speed);
	g->plane.y = prv_plane_x * sin(g->r_speed) + g->plane.y * cos(g->r_speed);
}
