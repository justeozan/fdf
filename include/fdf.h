/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sei <sei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:17:47 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/30 16:26:25 by sei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"

# define WIDTH	1920
# define HEIGHT	1080

# ifndef M
#  define M matrix
# endif

# ifndef SCALE_FACTOR
#  define SCALE_FACTOR 0.65
# endif

enum
{
	SPACE = 32,
	ESC = 65307,
	UP = 65362,
	DOWN = 65364,
	LEFT = 65361,
	RIGHT = 65363,
	MINUS = 65453,
	PLUS = 65451,
	STAR = 65450,
	DIV = 65455,
	UP_Z = 65365,
	DOWN_Z = 65366,
	ONE = 65436,
	TWO = 65433,
	THREE = 65435,
	FOUR = 65430,
	FIVE = 65437,
	SIX = 65432,
	Z = 122,
	X = 120,
	C = 99,
	V = 118,
	W = 119,
	D = 100,
	S = 115,
	A = 97
};

typedef struct s_argb
{
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_argb;

typedef struct s_switch
{
	int			isometric;
	int			wiggle;
	int			gradient;
	int			diagonal;
	int			bonus;
}	t_switch;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
	float		x_diff;
	float		y_diff;
	float		x_step;
	float		y_step;
	int			decision;
}	t_img;

typedef struct s_matrix
{
	int			x;
	int			y;
	int			z;
	int			color;
	int			x_proj;
	int			y_proj;
	int			z_proj;
	int			is_isometric;
	int			height;
	int			width;
	double		scale;
	double		depth;
	int			offset_x;
	int			offset_y;
	int			center_x;
	int			center_y;
	double		rot_x;
	double		rot_y;
	double		rot_z;
	void		*mlx;
	void		*win;
	t_img		imgs;
	t_switch	switchs;
}	t_matrix;

/*=================UTILS=================*/
/*-------------color_utils.c-------------*/
void		add_color(t_matrix **matrix);
t_argb		create_argb(int color);
int			create_color_gradient(float delta, t_argb color1, t_argb color2);
int			process_color(int curr_steps, int tot_steps, int color_ini,
				int color_end);
/*-------------map_utils-------------*/
void		ft_display_tab2d(char **strs);
int			get_width(char *line);
int			get_height(int *w, char *file_name);
char		**extract_first_part(char *s, int *i);
char		*get_color(char *line);
/*-------------proj_utils-------------*/
void		define_switchs(t_matrix **matrix);
void		define_scale(t_matrix **matrix);
void		define_rotation(t_matrix **matrix);
void		define_offset(t_matrix **matrix);
/*=================SRC=================*/
/*-------------apply_rotation-------------*/
void		apply_rot_x(t_matrix *point, double cos_a, double sin_a);
void		apply_rot_y(t_matrix *point, double cos_a, double sin_a);
void		apply_rot_z(t_matrix *point, double cos_a, double sin_a);
void		apply_rotation(t_matrix *point, t_matrix **matrix);
/*-------------create_frame-------------*/
void		apply_scaling(t_matrix *point, t_matrix **matrix);
void		apply_offset(t_matrix *point, t_matrix **matrix);
void		init_proj_map(t_matrix **matrix);
void		transform_img(t_matrix **matrix);
int			frame(t_matrix **matrix);
/*-------------draw_line-------------*/
void		put_pixel(t_img imgs, int x, int y, int color);
void		init_step(t_img *imgs, t_matrix *m0, t_matrix *m1);
void		draw_acute_slope(t_img imgs, t_matrix m0, t_matrix m1,
				t_matrix **m);
void		draw_acute_slope(t_img imgs, t_matrix m0, t_matrix m1,
				t_matrix **m);
void		draw_line(t_img imgs, t_matrix m0, t_matrix m1, t_matrix **matrix);
/*-------------free_fdf-------------*/
int			close_program(t_matrix **matrix, char *txt_err);
int			close_normal(t_matrix **matrix);
void		free_mx_data(void *ptr);
/*-------------get_map-------------*/
char		**line_parser(char *line);
int			fill_matrix_children(t_matrix **matrix, char **line2d,
				int w, int y);
void		fill_matrix_parent(t_matrix **matrix, char *f_name);
void		set_size_matrix(t_matrix ***matrix, char *file_name,
				int w, int h);
t_matrix	**get_map(char *file_name, t_matrix **matrix);
/*-------------init_fdf-------------*/
void		define_scale(t_matrix **matrix);
void		define_offset(t_matrix **matrix);
void		init_proj(t_matrix **matrix);
t_img		init_new_image(t_matrix	**matrix);
t_matrix	**init_fdf(char *file_name, t_matrix **matrix);
/*-------------key_manager-------------*/
int			is_key(int key);
void		do_key(int key, t_matrix **matrix);
int			manage_key(int key, t_matrix **matrix);
/*-------------main-------------*/
void		check_args(int ac, char **av);
int			main(int ac, char **av);
/*-------------others-------------*/
void		new_image(t_matrix **matrix);

#endif