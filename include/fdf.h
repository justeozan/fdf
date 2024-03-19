#ifndef FDF_H
#define FDF_H

#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

# define DATA matrix[0][0]

enum
{
	UP = 65362,
	DOWN = 65364,
	LEFT = 65361,
	RIGHT = 65363,
	SPACE = 32,
	MINUS = 65453,
	PLUS = 65451,
	STAR = 65450,
	DIV = 65455,
	ESC = 65307,
	UP_Z = 65365,
	DOWN_Z = 65366,
	ONE = 65436,
	TWO = 65433,
	THREE = 65435,
	FOUR = 65430,
	FIVE = 65437,
	SIX = 65432

};

enum
{
	READ_E = -1,
	MALLOC_E = -2,
	DIMENSIONS_E = -3
};

typedef struct s_fdf
{
	float		x;
	float		y;
	float		z;
	int			is_last;
	int			width_map;
	int			height_map;
	int			color;
	int			scale;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	int			is_isometric;
	double		angle;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

/**Error**/
void	ft_error(char	*msg);
void	error_handler(int error, t_fdf **matrix, int y);
void	free_matrix(t_fdf **matrix, int y);

/**Init_matrix**/
t_fdf	**init_matrix(char *filename);

/**Matrix_utils**/
int		words_counter(char const *str, char c);
int	get_height(char *filename);
int	get_width(char *filename);

/**Draw_map**/
void	draw_handler(t_fdf **matrix);
void	print_menu(t_fdf data);

/**Draw_utils**/
float	find_absolute(float a);
float	find_max(float a, float b);
void	set_param(t_fdf *a, t_fdf *b, t_fdf *data);
void	zoom(t_fdf *a, t_fdf *b, t_fdf *data);
void	isometric(t_fdf *dot, double angle);

/**Key_manager**/
int		key_handler(int key, t_fdf **matrix);

/**Window_manager**/
void	new_window(int key, t_fdf **matrix);


int	on_destroy(t_fdf **matrix);
#endif