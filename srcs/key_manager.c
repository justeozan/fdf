#include "../include/fdf.h"

int		is_key(int key)
{
	return (key == UP || key == DOWN || key == LEFT || key == RIGHT || key == SPACE
	|| key == MINUS || key == PLUS || key == STAR || key == DIV
	|| key == UP_Z || key == DOWN_Z);
}

void	do_key(int key, t_fdf **matrix)
{
	if (key == PLUS)
		DATA.scale += 3;
	if (key == MINUS)
		DATA.scale -= 3;
	if (key == UP_Z)
		DATA.z_scale += 1;
	if (key == DOWN_Z)
		DATA.z_scale -= 1;
	if (key == UP)
		DATA.shift_y -= 10;
	if (key == DOWN)
		DATA.shift_y += 10;
	if (key == LEFT)
		DATA.shift_x -= 10;
	if (key == RIGHT)
		DATA.shift_x += 10;
	if (key == STAR)
		DATA.angle += 0.05;
	if (key == DIV)
		DATA.angle -= 0.05;
	if (key == SPACE)
	{
		if (DATA.is_isometric == 1)
			DATA.is_isometric = 0;
		else
			DATA.is_isometric = 1;
	}
}

int		key_handler(int key, t_fdf **matrix)
{
	printf("key = %d\n", key);
	if (is_key(key))
	{
		mlx_clear_window(DATA.mlx_ptr, DATA.win_ptr);
		do_key(key, matrix);
		print_menu(DATA);
		draw_handler(matrix);
	}
	if (key == ONE || key == TWO || key == THREE || key == FOUR || key == FIVE)
		new_window(key, matrix);
	if (key == ESC)
		on_destroy(matrix);
	return (0);
}