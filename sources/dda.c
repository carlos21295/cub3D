/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:12:12 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/01/18 16:06:41 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_dir(t_rays *rays, t_game_params *g)
{
	if (rays->r_dir.x < 0)
	{
		rays->step.x = -1;
		rays->n_dist.x = (g->pos.x - rays->map.x) * rays->dist.x;
	}
	else
	{
		rays->step.x = 1;
		rays->n_dist.x = (rays->map.x + 1.0 - g->pos.x) * rays->dist.x;
	}
	if (rays->r_dir.y < 0)
	{
		rays->step.y = -1;
		rays->n_dist.y = (g->pos.y - rays->map.y) * rays->dist.y;
	}
	else
	{
		rays->step.y = 1;
		rays->n_dist.y = (rays->map.y + 1.0 - g->pos.y) * rays->dist.y;
	}
}

static void	ft_ray_hit(t_rays *rays, int *f_x, t_game_params *g)
{
	if (rays->n_dist.x < rays->n_dist.y)
	{
		rays->n_dist.x += rays->dist.x;
		rays->map.x += rays->step.x;
		rays->side = 0;
	}
	else
	{
		rays->n_dist.y += rays->dist.y;
		rays->map.y += rays->step.y;
		rays->side = 1;
	}
	if (g->map[(int)rays->map.x][(int)rays->map.y] == 49)
		rays->hit = 1;
	if (g->map[(int)rays->map.x][(int)rays->map.y] == 50 && (rays->map.x
		+ 0.5) != g->sprite.spt.x && (rays->map.y + 0.5 != g->sprite.spt.y))
		*f_x = 0;
	if (g->map[(int)rays->map.x][(int)rays->map.y] == 50 && *f_x == 0)
	{
		*f_x = 1;
		g->sprite.spt.x = rays->map.x + 0.5;
		g->sprite.spt.y = rays->map.y + 0.5;
		ft_parse_list(g);
	}
}

void		ft_dda(int *f_x, t_rays *rays, t_game_params *g)
{
	while (!rays->hit)
		ft_ray_hit(rays, f_x, g);
	if (!rays->side)
		rays->dist_wall = (rays->map.x - g->pos.x +
			(1 - rays->step.x) / 2) / rays->r_dir.x;
	else
		rays->dist_wall = (rays->map.y - g->pos.y +
			(1 - rays->step.y) / 2) / rays->r_dir.y;
}

static void	ft_fill_img(int cardinal, double wall_x,
				t_game_params *g, t_rays *rays)
{
	if (g->y > g->last_px_draw)
	{
		if (g->floor_path)
			fill_floor(g, rays, g->floor_txtr);
		else
			fill_fl_cl(g->floor, g);
	}
	else if (g->y < g->first_px_draw)
	{
		if (g->ceiling_path)
			fill_floor(g, rays, g->ceiling_txtr);
		else
			fill_fl_cl(g->ceiling, g);
	}
	else
	{
		if (cardinal == NO)
			fill_wall(wall_x, g, g->wall[NO]);
		if (cardinal == SO)
			fill_wall(wall_x, g, g->wall[SO]);
		if (cardinal == WE)
			fill_wall(wall_x, g, g->wall[WE]);
		if (cardinal == EA)
			fill_wall(wall_x, g, g->wall[EA]);
	}
}

void		ft_pixel(t_rays *rays, t_game_params *g)
{
	int			cardinal;
	double		wall_x;

	g->y = 0;
	ft_txtr_init(&wall_x, rays, g);
	ft_choose_texture_cardinal(rays, &cardinal);
	ft_floor_coordinates(wall_x, rays);
	while (g->y < g->window.y)
	{
		ft_fill_img(cardinal, wall_x, g, rays);
		g->y++;
	}
}
