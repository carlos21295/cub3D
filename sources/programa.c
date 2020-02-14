/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2037/11/28 11:50:43 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/01/18 16:42:39 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_new_image(t_game_params *g)
{
	mlx_destroy_image(g->mlx_ptr, g->img_ptr);
	g->img_ptr = mlx_new_image(g->mlx_ptr, g->window.x, g->window.y);
}

static int	ft_cycle(t_game_params *g)
{
	ft_new_image(g);
	if (!ft_diagonal_movement(g))
		ft_cardinal_movement(g);
	if (g->key.right == 1)
		ft_key_right(g);
	if (g->key.left == 1)
		ft_key_left(g);
	if (g->key.sprint == 1)
		g->m_speed = 0.3;
	else if (g->key.crouch)
		g->m_speed = 0.05;
	else
		g->m_speed = 0.1;
	ft_draw(g);
	return (0);
}

int			main(int argc, char **argv)
{
	t_game_params	g;

	if (argc < 2)
		ft_help();
	ft_read_file(argv[1], &g);
	ft_file_to_map(argv[1], &g);
	ft_init(&g);
	if (argc == 3 && !(ft_strncmp(argv[2], "--save", 6)))
		g.screenshot = 1;
	mlx_hook(g.win_ptr, 2, 1L << 0, ft_press, &g);
	mlx_hook(g.win_ptr, 3, 1L << 1, ft_release, &g);
	mlx_hook(g.win_ptr, 17, 0, ft_exit, 0);
	mlx_loop_hook(g.mlx_ptr, ft_cycle, &g);
	mlx_loop(g.mlx_ptr);
}
