/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:17:47 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/21 17:09:35 by ozasahin         ###   ########.fr       */
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

# define WIDTH 1920
# define HEIGHT 1080
# define FDF matrix[0][0]

# ifndef SCALE_FACTOR
#  define SCALE_FACTOR 0.85
# endif

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		x_diff;
	int		y_diff;
	int		x_step;
	int		y_step;
	int		decision;
}	t_img;

// typedef struct s_matrix
// {
// 	int		x;
// 	int		y;
// 	int		z;
// 	int		color;
// 	int		is_isometric;
// 	int		height;
// 	int		width;
// 	int		x_proj;
// 	int		y_proj;
// 	int		z_proj;
// 	int		valid;
// 	double	rot_x;
// 	double	rot_y;
// 	double	rot_z;
// 	double	depth;
// 	double	scale;
// 	int		offset_x;
// 	int		offset_y;
// 	void	*mlx;
// 	void	*win;
// 	t_img	img;
// 	// t_img	*img;
// }	t_matrix;

typedef struct s_matrix
{
	int		x;
	int		y;
	int		z;
	int		color;
	int		x_proj;
	int		y_proj;
	int		z_proj;
	int		valid;
	int		is_isometric;
	int		height;
	int		width;
	double	scale;
	double	angle;
	double	depth;
	int		offset_x;
	int		offset_y;
	void	*mlx;
	void	*win;
	t_img	*img;
}	t_matrix;


/*-------------displays-------------*/
void	display_matrix(t_matrix **matrix, int w, int h);
/*-------------draw_line-------------*/
void	set_param(t_matrix *a, t_matrix *b, t_matrix *data);
void	bresenham(t_matrix a, t_matrix b, t_matrix *data);
void	draw_line_h(t_img img, t_matrix m0, t_matrix m1);
void	draw_line_g(t_matrix **matrix);
/*-------------fdf-------------*/
void	define_offset(t_matrix **matrix, double scale);
void	define_scale(t_matrix **matrix);
void	init_proj(t_matrix **matrix);
t_img	*init_new_image(t_matrix	**matrix);
void	init_fdf(char *file_name, t_matrix **matrix);
/*-------------free_fdf-------------*/
void	free_mx_data(void *ptr);
/*-------------get_map-------------*/
char	**line_parser(char *line);
void	fill_matrix_children(t_matrix **matrix, char **line2d, int w, int y);
void	fill_matrix_parent(t_matrix **matrix, char *f_name, int w, int h);
void	set_size_matrix(t_matrix ***matrix, char *file_name, int w, int h);
t_matrix	**get_map(char *file_name);
/*-------------main-------------*/
void	check_args(int ac, char **av);
int		close_hook(t_matrix **matrix);
void	apply_scaling(t_matrix *item, t_matrix **matrix);
void	apply_offset(t_matrix *item, t_matrix **matrix);
void	init_proj_map(t_matrix **matrix);
void	transform_img(t_matrix **matrix);
int		frame(t_matrix **matrix);
int		main(int ac, char **av);
/*-------------map_utils-------------*/
void	ft_display_tab2d(char **strs);
int		get_width(char *line);
int		get_height(char *file_name);


#endif