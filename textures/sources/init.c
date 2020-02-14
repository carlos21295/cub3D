/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:46:18 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/01/18 18:07:08 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_pos_init(t_game_params *g)
{
	if (g->init_dir == 'N' || g->init_dir == 'S')
	{
		g->dir.x = 1;
		g->dir.y = 0;
		g->plane.x = 0;
		g->plane.y = 0.66;
	}
	else if (g->init_dir == 'E' || g->init_dir == 'W')
	{
		g->dir.x = 0;
		g->dir.y = 1;
		g->plane.x = 0.66;
		g->plane.y = 0;
	}
	g->dir.x *= g->init_dir == 'N' ? -1 : 1;
	g->plane.y *= g->init_dir == 'S' ? -1 : 1;
	g->dir.y *= g->init_dir == 'W' ? -1 : 1;
	g->plane.x *= g->init_dir == 'W' ? -1 : 1;
}

static void	ft_sprite_init(t_game_params *g)
{
	if (!(g->sprite.img_ptr = mlx_xpm_file_to_image(g->mlx_ptr,
				g->sprite_path, &g->sprite.spt_w, &g->sprite.spt_h)))
		ft_exit_error("\nError\nWrong sprite texture path\n");
	if (!(g->weapon.img_ptr = mlx_xpm_file_to_image(g->mlx_ptr,
				"./textures/sniper.xpm", &g->weapon.spt_w, &g->weapon.spt_h)))
		ft_exit_error("\nError\nWrong weapon texture path\n");
	g->sprite.img_str = mlx_get_data_addr(g->sprite.img_ptr,
				&(g->sprite.bpp), &(g->sprite.size_line), &(g->sprite.endian));
	g->weapon.img_str = mlx_get_data_addr(g->weapon.img_ptr,
				&(g->weapon.bpp), &(g->weapon.size_line), &(g->weapon.endian));
}

static void	ft_floor_ceiling_init(t_game_params *g)
{
	if (g->floor_path)
	{
		if (!(g->floor_txtr.img_ptr = mlx_xpm_file_to_image(g->mlx_ptr,
				g->floor_path, &g->floor_txtr.txtr_w, &g->floor_txtr.txtr_h)))
			ft_exit_error("\nError\nWrong floor texture path\n");
		g->floor_txtr.img_str = mlx_get_data_addr(g->floor_txtr.img_ptr,
				&(g->floor_txtr.bpp), &(g->floor_txtr.size_line),
					&(g->floor_txtr.endian));
	}
	if (g->ceiling_path)
	{
		if (!(g->ceiling_txtr.img_ptr = mlx_xpm_file_to_image(g->mlx_ptr,
				g->ceiling_path, &g->ceiling_txtr.txtr_w,
					&g->ceiling_txtr.txtr_h)))
			ft_exit_error("\nError\nWrong ceiling texture path\n");
		g->ceiling_txtr.img_str = mlx_get_data_addr(g->ceiling_txtr.img_ptr,
				&(g->ceiling_txtr.bpp), &(g->ceiling_txtr.size_line),
					&(g->ceiling_txtr.endian));
	}
}

static void	ft_wall_init(t_game_params *g)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (!(g->wall[i].img_ptr = mlx_xpm_file_to_image(g->mlx_ptr,
				g->wall_path[i], &g->wall[i].txtr_w, &g->wall[i].txtr_h)))
		{
			if (i == NO)
				ft_exit_error("\nError\nWrong North texture path\n");
			else if (i == SO)
				ft_exit_error("\nError\nWrong South texture path\n");
			else if (i == WE)
				ft_exit_error("\nError\nWrong West texture path\n");
			else if (i == EA)
				ft_exit_error("\nError\nWrong East texture path\n");
		}
		g->wall[i].img_str = mlx_get_data_addr(g->wall[i].img_ptr,
			&(g->wall[i].bpp), &(g->wall[i].size_line), &(g->wall[i].endian));
		i++;
	}
}

void		ft_init(t_game_params *g)
{
	g->window.x = g->window.x > 2560 ? 2560 : g->window.x;
	g->window.y = g->window.y > 1400 ? 1400 : g->window.y;
	ft_pos_init(g);
	g->r_speed = 0.1;
	g->mlx_ptr = mlx_init();
	g->win_ptr = mlx_new_window(g->mlx_ptr, g->window.x, g->window.y, "Cub3D");
	g->img_ptr = mlx_new_image(g->mlx_ptr, g->window.x, g->window.y);
	g->img_str = mlx_get_data_addr(g->img_ptr,
				&(g->bpp), &(g->size_line), &(g->endian));
	ft_sprite_init(g);
	ft_floor_ceiling_init(g);
	ft_wall_init(g);
	g->key.up = 0;
	g->key.down = 0;
	g->key.right = 0;
	g->key.left = 0;
	g->key.strafe_r = 0;
	g->key.strafe_l = 0;
	g->object = NULL;
	g->w = 0;
	g->key.q = 0;
	g->key.crouch = 0;
	g->screenshot = 0;
}
