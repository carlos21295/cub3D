/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:36:31 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/01/18 15:59:47 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit_error(char *str)
{
	int		pos;

	pos = 0;
	while (str[pos])
	{
		write(1, &str[pos], 1);
		pos++;
	}
	exit(EXIT_FAILURE);
}

int		ft_exit(void)
{
	exit(0);
	return (0);
}

void	ft_help(void)
{
	write(1, "\n----------------Play------------------\n", 39);
	write(1, "\n\n            ./cub3D *.cub             \n", 39);
	write(1, "\n          *.cub = map file            \n\n", 40);
	write(1, "\n----------------Keys------------------\n", 39);
	write(1, "\n\nMove forward:                   [W]\n", 39);
	write(1, "Move back:                      [S]\n", 36);
	write(1, "Strafe right:                   [D]\n", 36);
	write(1, "Strafe left:                    [A]\n", 36);
	write(1, "Rotate the camera to the right: [->]\n", 37);
	write(1, "Rotate the camera to the left:  [<-]\n", 37);
	write(1, "exit:                           [esc]\n\n", 39);
	ft_exit();
}

void	ft_spt_del(t_game_params *g, t_list_object **obj)
{
	t_list_object	*aux;

	aux = (*obj);
	if ((int)g->pos.x == (int)(*obj)->pos.x &&
		(int)g->pos.y == (int)(*obj)->pos.y)
	{
		free(*obj);
		(*obj) = NULL;
	}
	else
	{
		while (aux->next && (int)g->pos.x != (int)aux->next->pos.x &&
			(int)g->pos.y != (int)aux->next->pos.y)
			aux = aux->next;
		aux->next = aux->next->next;
	}
}
