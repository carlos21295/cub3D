/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:32:11 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/01/18 12:10:24 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list_object	*ft_obj_new(t_game_params *g)
{
	t_list_object	*aux;

	aux = malloc(sizeof(t_list_object));
	aux->pos.x = g->sprite.spt.x;
	aux->pos.y = g->sprite.spt.y;
	aux->object = g->map[(int)g->sprite.spt.x][(int)g->sprite.spt.y];
	aux->next = NULL;
	return (aux);
}

t_list_object	*ft_objlast(t_list_object *object)
{
	t_list_object	*aux;

	if (!object)
		return (NULL);
	aux = object;
	while (aux->next)
		aux = aux->next;
	return (aux);
}

void			ft_objadd_back(t_list_object **object, t_list_object *new)
{
	t_list_object *aux;

	if (object)
	{
		aux = *object;
		if (!*object)
			*object = new;
		else
		{
			aux = ft_objlast(*object);
			aux->next = new;
		}
	}
}

void			ft_parse_list(t_game_params *g)
{
	t_list_object			*aux;

	aux = g->object;
	while (aux)
	{
		if (aux->pos.x == g->sprite.spt.x && aux->pos.y == g->sprite.spt.y)
			return ;
		aux = aux->next;
	}
	aux = ft_obj_new(g);
	ft_objadd_back(&g->object, aux);
	aux = g->object;
}
