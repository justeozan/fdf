#include "../include/fdf.h"

void	print_menu(t_fdf data)
{
	char *menu;

	menu = "up, down, left, right: move picture";
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, 10, 0x03fc35, menu);
	menu = "Space: 3d/2d mode; +, -: zoom";
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, 25, 0x03fc35, menu);
	menu = "Page up, pager down: z-scale; *, /: rotation";
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, 40, 0x03fc35, menu);
	menu = "f: full screen mode";
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, 55, 0x03fc35, menu);
}

void	bresenham(t_fdf a, t_fdf b, t_fdf *data)
{
	float	step_x;
	float	step_y;
	float	max;

	set_param(&a, &b, data);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = find_max(find_absolute(step_x), find_absolute(step_y));
	step_x /= max;
	step_y /= max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, a.x, a.y, 250);
		a.x += step_x;
		a.y += step_y;
		if (a.x > data->win_x || a.y > data->win_y || a.y < 0 || a.x < 0)
			break;
	}
}

void	draw_handler(t_fdf **matrix)
{
	int	y;
	int	x;

	print_menu(DATA);
	y = 0;
	while (matrix[y] != NULL)
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				bresenham(matrix[y][x], matrix[y + 1][x], &DATA);
			if (!matrix[y][x].is_last)
				bresenham(matrix[y][x], matrix[y][x + 1], &DATA);
			if (matrix[y][x].is_last)
				break;
			x++;
		}
		y++;
	}
	
}