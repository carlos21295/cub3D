/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:36:14 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/01/18 16:33:02 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		check_wall(int x, t_game_params *g)
{
	int		f_x;
	t_rays	wall;

	f_x = 1;
	wall.camera_x = ((2 * x) / (double)g->window.x) - 1;
	wall.r_dir.x = g->dir.x + g->plane.x * wall.camera_x;
	wall.r_dir.y = g->dir.y + g->plane.y * wall.camera_x;
	wall.map.x = (int)g->pos.x;
	wall.map.y = (int)g->pos.y;
	wall.dist.x = fabs(1 / wall.r_dir.x);
	wall.dist.y = fabs(1 / wall.r_dir.y);
	wall.hit = 0;
	ft_dir(&wall, g);
	ft_dda(&f_x, &wall, g);
	return (wall.dist_wall);
}

void		ft_spt_init(t_game_params *g, t_list_object *obj, double inv)
{
	obj->v_spt.x = obj->pos.x - g->pos.x;
	obj->v_spt.y = obj->pos.y - g->pos.y;
	obj->transform.x = inv * (g->dir.y * obj->v_spt.x -
		g->dir.x * obj->v_spt.y);
	obj->transform.y = inv * (-g->plane.y * obj->v_spt.x +
		g->plane.x * obj->v_spt.y);
	if (obj->transform.y < 0.5 && obj->transform.y > 0)
		obj->transform.y = 0.5;
	obj->spt_x = (int)((g->window.x / 2) *
		(1 + obj->transform.x / obj->transform.y));
	g->spt_size = abs((int)(g->window.y / obj->transform.y) / 2);
	g->spt_last_px.y = (g->window.y / 2) + (g->spt_size / 2) - g->key.crouch;
	g->spt_first_px.y = (g->window.y / 2) - (g->spt_size / 2) - g->key.crouch;
	g->spt_first_px.x = -g->spt_size / 2 + obj->spt_x;
	g->spt_last_px.x = g->spt_size / 2 + obj->spt_x;
}

static void	ft_sort_loop(t_game_params *g)
{
	t_list_object	big;
	t_list_object	*sort;
	t_list_object	*tmp;

	ft_bubble(&g->object);
	big = *g->object;
	big.next = NULL;
	tmp = malloc(sizeof(t_list_object));
	*tmp = big;
	sort = tmp;
	g->object = g->object->next;
	while (g->object)
	{
		ft_bubble(&g->object);
		big = *g->object;
		big.next = NULL;
		tmp = malloc(sizeof(t_list_object));
		*tmp = big;
		ft_objadd_back(&sort, tmp);
		g->object = g->object->next;
	}
	g->object = sort;
}

void		ft_sort(t_game_params *g)
{
	t_list_object	*aux;

	if (g->object)
	{
		aux = g->object;
		while (aux)
		{
			aux->dist = (aux->pos.x - g->pos.x) * (aux->pos.x - g->pos.x) +
				(aux->pos.y - g->pos.y) * (aux->pos.y - g->pos.y);
			aux = aux->next;
		}
		ft_sort_loop(g);
		aux = g->object;
	}
}

void		ft_bubble(t_list_object **obj)
{
	t_list_object	*aux;
	t_list_object	*prev;
	t_list_object	*prevb;
	t_list_object	*big;

	aux = *obj;
	big = aux;
	while (aux && aux->pos.x)
	{
		if (aux->dist > big->dist)
		{
			prevb = prev;
			big = aux;
		}
		prev = aux;
		aux = aux->next;
	}
	if (big != *obj)
	{
		prevb->next = big->next;
		big->next = *obj;
		*obj = big;
	}
}
