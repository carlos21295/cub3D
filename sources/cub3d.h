/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:51:54 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/01/18 16:37:34 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# define NO 0
# define SO 1
# define WE 2
# define EA 3

typedef struct	s_vector
{
	double	x;
	double	y;
}				t_vector;
typedef struct	s_key
{
	int		up;
	int		down;
	int		strafe_r;
	int		strafe_l;
	int		left;
	int		right;
	int		sprint;
	int		crouch;
	int		q;
}				t_key;

typedef struct	s_list_object
{
	t_vector				pos;
	int						object;
	double					dist;
	t_vector				v_spt;
	t_vector				transform;
	int						spt_x;
	struct s_list_object	*next;
}				t_list_object;

typedef struct	s_texture
{
	char			*img_str;
	void			*img_ptr;
	int				bpp;
	int				size_line;
	int				endian;
	int				txtr_h;
	int				txtr_w;
}				t_texture;

typedef struct	s_sprite
{
	char			*img_str;
	void			*img_ptr;
	int				bpp;
	int				size_line;
	int				endian;
	int				spt_h;
	int				spt_w;
	t_vector		spt;
}				t_sprite;

typedef struct	s_game_params
{
	t_vector		pos;
	t_vector		dir;
	t_vector		plane;
	char			init_dir;

	double			m_speed;
	double			r_speed;

	t_vector		window;

	void			*mlx_ptr;
	void			*win_ptr;

	int				line_size;
	int				first_px;
	int				last_px;
	int				first_px_draw;
	int				last_px_draw;
	double			intensity;

	int				spt_size;
	t_vector		spt_first_px;
	t_vector		spt_last_px;

	void			*img_ptr;
	char			*img_str;
	int				bpp;
	int				size_line;
	int				endian;

	t_texture		wall[4];
	t_texture		floor_txtr;
	t_texture		ceiling_txtr;
	t_sprite		sprite;
	t_sprite		weapon;
	int				w;

	t_list_object	*object;

	t_key			key;

	char			*wall_path[4];
	char			*sprite_path;
	char			*floor_path;
	char			*ceiling_path;
	int				floor;
	int				ceiling;

	char			**map;
	int				col;
	int				row;
	int				check;
	int				cardinal;
	int				x;
	int				y;
	int				screenshot;

}				t_game_params;

typedef struct	s_rays
{
	double		camera_x;
	double		camera_spt;

	t_vector	r_dir;
	t_vector	map;
	t_vector	n_dist;
	t_vector	dist;
	t_vector	floor;

	double		dist_wall;

	t_vector	step;

	int			hit;
	int			side;
	int			sprite;
}				t_rays;

void			ft_init(t_game_params *g);
int				ft_press(int key, t_game_params *g);
int				ft_release(int key, t_game_params *g);
void			ft_key_up(t_game_params *g);
void			ft_key_down(t_game_params *g);
void			ft_key_right(t_game_params *g);
void			ft_key_left(t_game_params *g);
void			ft_draw(t_game_params *g);
int				ft_exit(void);
void			ft_read_file(char *argv, t_game_params *g);
void			ft_file_to_map(char *argv, t_game_params *g);
int				ft_no(char **line, t_game_params *g);
int				ft_so(char **line, t_game_params *g);
int				ft_we(char **line, t_game_params *g);
int				ft_ea(char **line, t_game_params *g);
int				ft_sprite(char **line, t_game_params *g);
int				ft_check_line(char **line, int lt, t_game_params *g);
int				ft_elements(char **line, t_game_params *g);
int				ft_col(char **line);
void			ft_key_strafe_l(t_game_params *g);
void			ft_key_strafe_r(t_game_params *g);
void			ft_parse_list(t_game_params *g);
void			ft_sort(t_game_params *g);
void			ft_spt(t_game_params *g);
void			ft_dir(t_rays *rays, t_game_params *g);
void			ft_dda(int *f_x, t_rays *rays, t_game_params *g);
void			ft_key_d(double x, double y, t_game_params *g);
void			ft_exit_error(char *str);
void			ft_help(void);
void			ft_cardinal_movement(t_game_params *g);
int				ft_diagonal_movement(t_game_params *g);
void			ft_choose_texture_cardinal(t_rays *rays, int *cardinal);
void			fill_fl_cl(int color, t_game_params *g);
void			fill_floor(t_game_params *g, t_rays *rays, t_texture t);
void			fill_wall(double wall_x, t_game_params *g, t_texture t);
void			ft_txtr_init(double *wall_x, t_rays *rays, t_game_params *g);
void			ft_spt_del(t_game_params *g, t_list_object **obj);
void			ft_pixel(t_rays *rays, t_game_params *g);
void			ft_floor_coordinates(double wall_x, t_rays *rays);
t_list_object	*ft_obj_new(t_game_params *g);
t_list_object	*ft_objlast(t_list_object *object);
void			ft_objadd_back(t_list_object **object, t_list_object *new);
void			ft_parse_list(t_game_params *g);
void			ft_bubble(t_list_object **obj);
double			check_wall(int x, t_game_params *g);
void			ft_spt_init(t_game_params *g, t_list_object *obj, double inv);
void			ft_screenshot(t_game_params *g);

#endif
