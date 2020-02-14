/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:25:48 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/01/18 15:23:03 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_sprite_draw(int x, int y, t_game_params *g, t_sprite *s)
{
	int		pos;
	int		pos_s;
	int		x_t;
	int		y_s;
	void	*cmp;

	pos = x * (g->bpp / 8) + y * g->size_line;
	x_t = (x - g->spt_first_px.x) / ((g->spt_last_px.x - g->spt_first_px.x + 2)
		/ (double)s->spt_w);
	y_s = ((y - g->spt_first_px.y) / ((g->spt_last_px.y - g->spt_first_px.y + 2)
		/ (double)s->spt_h));
	pos_s = x_t * (s->bpp / 8) + y_s * s->size_line;
	ft_memcpy(&cmp, &s->img_str[pos_s], 4);
	if ((unsigned int)cmp != 0xFF000000)
	{
		while (pos < (x + 1) * (g->bpp / 8) + y * g->size_line)
		{
			g->img_str[pos] = s->img_str[pos_s];
			pos_s++;
			pos++;
		}
	}
}

static void	ft_print_weapon(t_game_params *g)
{
	int				x;
	int				y;

	g->spt_last_px.y = g->window.y;
	g->spt_first_px.y = g->window.y - (g->window.y / 2);
	g->spt_first_px.x = g->window.x - (2 * g->window.y / 3);
	g->spt_last_px.x = g->window.x;
	x = g->spt_first_px.x;
	while (x < g->spt_last_px.x)
	{
		y = g->spt_first_px.y;
		while (y < g->spt_last_px.y)
		{
			ft_sprite_draw(x, y, g, &g->weapon);
			y++;
		}
		x++;
	}
}

static void	ft_print_sprites(t_list_object *aux, t_game_params *g)
{
	int				x;
	int				y;

	x = g->spt_first_px.x;
	while (x < g->spt_last_px.x)
	{
		y = g->spt_first_px.y;
		if (aux->transform.y > 0 && x > 0 && x < g->window.x &&
			aux->transform.y < check_wall(x, g))
			while (y < g->spt_last_px.y)
			{
				ft_sprite_draw(x, y, g, &g->sprite);
				y++;
			}
		x++;
	}
}

void		ft_spt(t_game_params *g)
{
	double			inv;
	t_list_object	*aux;

	if (g->object)
	{
		inv = 1.0 / (g->plane.x * g->dir.y - g->plane.y * g->dir.x);
		aux = g->object;
		while (aux)
		{
			ft_spt_init(g, aux, inv);
			ft_print_sprites(aux, g);
			aux = aux->next;
		}
	}
	if (g->w)
		ft_print_weapon(g);
}
