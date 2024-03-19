/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:17:47 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/19 17:12:42 by ozasahin         ###   ########.fr       */
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

typedef struct s_matrix
{
	int		x;
	int		y;
	int		z;
	int		color;
	int		height;
	int		width;
	int		x_proj;
	int		y_proj;
	int		z_temp;
	int		valid;
	double	rot_x;
	double	rot_y;
	double	rot_z;
	double	depth;
	double	scale;
	int		offset_x;
	int		offset_y;
	void	*mlx;
	void	*win;
	t_img	img;
}	t_matrix;

// typedef struct s_fdf
// {
// 	void	*mlx;
// 	void	*win;
// 	int		x;
// 	int		y;
// 	int		z;
// }	t_fdf;

/*-------------displays-------------*/
void	display_matrix(t_matrix **matrix, int w, int h);
/*-------------fdf_utils-------------*/
int		get_width(char *line);
int		get_height(char *file_name);
/*-------------fdf-------------*/
void	fdf(char *file_name);
/*-------------free_fdf-------------*/
void	free_mx_data(void *ptr);
/*-------------get_map-------------*/
char	**line_parser(char *line);
void	fill_matrix_children(t_matrix **matrix, char **line2d, int w, int y);
void	fill_matrix_parent(t_matrix **matrix, char *f_name, int w, int h);
void	set_size_matrix(t_matrix ***matrix, char *file_name, int *w, int *h);
t_matrix	**get_map(char *file_name);
/*-------------main-------------*/
// Not needed

#endif