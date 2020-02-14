/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:30:03 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/01/18 16:06:05 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_txtr_init(double *wall_x, t_rays *rays, t_game_params *g)
{
	g->line_size = (int)(g->window.y / rays->dist_wall);
	g->first_px = g->window.y / 2 - g->line_size / 2 - g->key.crouch;
	g->last_px = g->window.y / 2 + g->line_size / 2 - g->key.crouch;
	g->first_px_draw = g->first_px < 0 ? 0 : g->first_px;
	g->last_px_draw = g->last_px >= g->window.y ? g->window.y - 1 : g->last_px;
	if (!rays->side)
	{
		*wall_x = g->pos.y + rays->dist_wall * rays->r_dir.y;
	}
	else
	{
		*wall_x = g->pos.x + rays->dist_wall * rays->r_dir.x;
	}
	*wall_x -= floor(*wall_x);
}

void	ft_choose_texture_cardinal(t_rays *rays, int *cardinal)
{
	if (rays->side == 0)
	{
		if (rays->step.x < 0)
			*cardinal = WE;
		else
			*cardinal = EA;
	}
	else
	{
		if (rays->step.y > 0)
			*cardinal = NO;
		else
			*cardinal = SO;
	}
}

void	fill_fl_cl(int color, t_game_params *g)
{
	int				pos;
	unsigned int	bpp_color;

	bpp_color = mlx_get_color_value(g->mlx_ptr, color);
	pos = g->x * (g->bpp / 8) + g->y * g->size_line;
	while (pos < (g->x + 1) * (g->bpp / 8) + g->y * g->size_line)
	{
		g->img_str[pos] = (bpp_color & 0xFFFFFF);
		bpp_color >>= 8;
		pos++;
	}
}

void	fill_floor(t_game_params *g, t_rays *rays, t_texture t)
{
	int				pos;
	unsigned int	pos_t;
	double			c_dist;
	double			weight;
	t_vector		floor;

	c_dist = fabs(g->window.y / (2.0 * (g->y + g->key.crouch) - g->window.y));
	weight = c_dist / rays->dist_wall;
	floor.x = weight * rays->floor.x + (1.0 - weight) * g->pos.x;
	floor.y = weight * rays->floor.y + (1.0 - weight) * g->pos.y;
	floor.x = ((int)(floor.x * t.txtr_w)) % t.txtr_w;
	floor.y = (int)(floor.y * t.txtr_h) % t.txtr_h;
	pos = g->x * (g->bpp / 8) + g->y * g->size_line;
	pos_t = floor.x * (g->bpp / 8) + floor.y * t.size_line;
	while (pos < (g->x + 1) * (g->bpp / 8) + g->y * g->size_line)
	{
		g->img_str[pos] = t.img_str[pos_t];
		pos_t++;
		pos++;
	}
}

void	fill_wall(double wall_x, t_game_params *g, t_texture t)
{
	int		pos;
	int		pos_t;
	int		y_t;

	pos = g->x * (g->bpp / 8) + g->y * g->size_line;
	y_t = ((g->y - g->first_px) / ((g->last_px - g->first_px + 2)
		/ ((double)t.txtr_h)));
	pos_t = (int)(wall_x * (double)t.txtr_w) * (t.bpp / 8) + y_t * t.size_line;
	while (pos < (g->x + 1) * (g->bpp / 8) + g->y * g->size_line)
	{
		g->img_str[pos] = t.img_str[pos_t];
		pos_t++;
		pos++;
	}
}
