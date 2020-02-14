/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:27:27 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/01/18 15:51:26 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_parse_line(char **line, int last, t_game_params *g)
{
	g->col = ft_col(line);
	g->check = ft_check_line(line, last, g);
	g->row++;
	free(*line);
}

void		ft_read_file(char *argv, t_game_params *g)
{
	int		fd;
	char	*line;
	int		last;

	g->cardinal = 0;
	g->check = 0;
	g->row = 0;
	fd = open(argv, O_RDONLY);
	while (g->check < 8 && get_next_line(fd, &line) == 1)
	{
		g->check += ft_elements(&line, g);
		free(line);
		line = NULL;
	}
	while ((last = get_next_line(fd, &line)) && !*line)
		free(line);
	ft_parse_line(&line, last, g);
	while ((last = get_next_line(fd, &line)) && g->check != -1)
		ft_parse_line(&line, last, g);
	g->check = ft_check_line(&line, last, g);
	free(line);
	close(fd);
	if (g->cardinal != 1)
		ft_exit_error("\nError\nMore than one starting point\n");
}

static void	ft_save_map(char **line, int row, t_game_params *g)
{
	int		pos;
	int		i;

	i = 0;
	pos = 0;
	while ((*line)[pos])
	{
		if ((*line)[pos] != ' ')
		{
			g->map[row][i] = (*line)[pos];
			i++;
		}
		g->map[row][i] = 0;
		pos++;
	}
}

void		ft_file_to_map(char *argv, t_game_params *g)
{
	int		fd;
	char	*line;
	int		row;

	if (!(g->map = (char **)malloc(sizeof(char *) * (g->row + 1))))
		ft_exit_error("\nError\nMemory map fail\n");
	row = 0;
	while (row <= g->row)
		if (!(g->map[row++] = (char *)malloc(sizeof(char) * (g->col + 1))))
			ft_exit_error("\nError\nMemory map fail\n");
	g->map[row] = NULL;
	fd = open(argv, O_RDONLY);
	row = 0;
	while (get_next_line(fd, &line))
	{
		if (*line == '1')
			ft_save_map(&line, row++, g);
		free(line);
	}
	ft_save_map(&line, row, g);
	g->map[(int)g->pos.x][(int)g->pos.y] = '0';
	free(line);
	close(fd);
}
