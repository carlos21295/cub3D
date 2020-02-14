/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:05:32 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/01/18 16:48:08 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_floor_coordinates(double wall_x, t_rays *rays)
{
	if (rays->side == 0 && rays->r_dir.x > 0)
	{
		rays->floor.x = rays->map.x;
		rays->floor.y = rays->map.y + wall_x;
	}
	else if (rays->side == 0 && rays->r_dir.x < 0)
	{
		rays->floor.x = rays->map.x + 1.0;
		rays->floor.y = rays->map.y + wall_x;
	}
	else if (rays->side == 1 && rays->r_dir.y > 0)
	{
		rays->floor.x = rays->map.x + wall_x;
		rays->floor.y = rays->map.y;
	}
	else
	{
		rays->floor.x = rays->map.x + wall_x;
		rays->floor.y = rays->map.y + 1.0;
	}
}

static void	ft_draw_screen(int f_x, t_rays *rays, t_game_params *g)
{
	rays->camera_x = ((2 * g->x) / (double)g->window.x) - 1;
	rays->r_dir.x = g->dir.x + g->plane.x * rays->camera_x;
	rays->r_dir.y = g->dir.y + g->plane.y * rays->camera_x;
	rays->map.x = (int)g->pos.x;
	rays->map.y = (int)g->pos.y;
	rays->dist.x = fabs(1 / rays->r_dir.x);
	rays->dist.y = fabs(1 / rays->r_dir.y);
	rays->hit = 0;
	ft_dir(rays, g);
	ft_dda(&f_x, rays, g);
	ft_pixel(rays, g);
	g->x++;
}

static void	ft_special(t_game_params *g)
{
	if (g->object || g->w)
	{
		ft_sort(g);
		ft_spt(g);
	}
	if (g->screenshot == 1)
	{
		ft_screenshot(g);
		ft_exit();
	}
}

void		ft_draw(t_game_params *g)
{
	t_rays		rays;
	int			f_x;

	f_x = 0;
	g->x = 0;
	while (g->x < g->window.x)
		ft_draw_screen(f_x, &rays, g);
	if (g->map[(int)g->pos.x][(int)g->pos.y] == 50 && !g->w)
	{
		g->w = 1;
		ft_spt_del(g, &g->object);
		g->map[(int)g->pos.x][(int)g->pos.y] = 48;
	}
	if (g->key.q)
	{
		(g->map[(int)g->pos.x + 1][(int)g->pos.y + 1] = 50);
		g->w = 0;
	}
	ft_special(g);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_ptr, 0, 0);
}
