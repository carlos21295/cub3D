/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:28:03 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/01/18 16:32:06 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

static int	get_color(t_game_params *g, int x, int y)
{
	int	rgb;
	int	color;

	color = *(int*)(g->img_str
			+ (4 * (int)g->window.x * ((int)g->window.y - 1 - y))
			+ (4 * x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

static int	write_bmp_header(int fd, int filesize, t_game_params *g)
{
	int				i;
	unsigned char	bmpfileheader[54];

	i = 0;
	while (i < 54)
		bmpfileheader[i++] = (unsigned char)(0);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	set_int_in_char(bmpfileheader + 2, filesize);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	set_int_in_char(bmpfileheader + 18, g->window.x);
	set_int_in_char(bmpfileheader + 22, g->window.y);
	bmpfileheader[27] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

static int	write_bmp_data(int file, t_game_params *g, int pad)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					y;
	int					x;
	int					color;

	y = 0;
	while (y < (int)g->window.y)
	{
		x = 0;
		while (x < (int)g->window.x)
		{
			color = get_color(g, x, y);
			if (write(file, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(file, &zero, pad) < 0)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void		ft_screenshot(t_game_params *g)
{
	int file;
	int filesize;
	int	pad;

	pad = (4 - ((int)g->window.x * 3) % 4) % 4;
	filesize = 54 + (3 * ((int)g->window.x + pad) * (int)g->window.y);
	if ((file = open("screenshot.bmp", O_WRONLY | O_CREAT
		| O_TRUNC | O_APPEND, 777)) < 0)
		ft_exit_error("\nError\nFailed bmp file creation\n");
	if (!write_bmp_header(file, filesize, g))
		ft_exit_error("\nError\nFailed bmp file creation\n");
	if (!write_bmp_data(file, g, pad))
		ft_exit_error("\nError\nFailed bmp file creation\n");
	close(file);
}
