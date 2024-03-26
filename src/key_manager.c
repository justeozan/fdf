/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:07:58 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/26 15:10:16 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int is_key(int key)
{
	return(key == UP || key == DOWN || key == LEFT || key == RIGHT
	|| key == SPACE || key == MINUS || key == PLUS || key == STAR || key == DIV
	|| key == UP_Z || key == DOWN_Z || key == V || key == W || key == D
	|| key == S || key == A);
}

void	do_key(int key, t_matrix **matrix)
{
	if (key == PLUS && FDF.scale < SCALE_FACTOR * 1000)
		FDF.scale += 1 * FDF.scale;
	if (key == MINUS && FDF.scale > SCALE_FACTOR)
		FDF.scale -= 1 * abs((int)FDF.scale) / 2;
	if (key == UP_Z)
		FDF.depth += 0.5;
	if (key == DOWN_Z)
		FDF.depth -= 0.5;
	if (key == UP)
		FDF.offset_y += 10;
	if (key == DOWN)
		FDF.offset_y -= 10;
	if (key == LEFT)
		FDF.offset_x += 10;
	if (key == RIGHT)
		FDF.offset_x -= 10;
	if (key == STAR && FDF.angle < 1)
		FDF.angle += 0.02;
	if (key == DIV && FDF.angle > 0)
		FDF.angle -= 0.02;
	if (key == W)
		FDF.rot_x += 0.10;
	if (key == S)
		FDF.rot_x -= 0.10;
	if (key == D)
		FDF.rot_y += 0.10;
	if (key == A)
		FDF.rot_y -= 0.10;
	if (key == V)
	{
		if (FDF.is_isometric == 1)
			FDF.is_isometric = 0;
		else
			FDF.is_isometric = 1;
	}
}

void	draw_black(t_matrix **matrix)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(FDF.imgs, x, y, 0);
			x++;
		}
		y++;
	}
}

void	new_image(t_matrix **matrix)
{
	FDF.imgs.img = mlx_new_image(FDF.mlx, WIDTH, HEIGHT);
	FDF.imgs.addr = mlx_get_data_addr(FDF.imgs.img, &FDF.imgs.bits_per_pixel, &FDF.imgs.line_len, &FDF.imgs.endian);
}

int	manage_key(int key, t_matrix **matrix)
{
	ft_printf("key = %d\n", key);
	if (is_key(key))
	{
		mlx_destroy_image(FDF.mlx, FDF.imgs.img);
		new_image(matrix);
		// if (mlx_put_image_to_window(FDF.mlx, FDF.win, FDF.imgs.img, 0, 0) < 0)
		// 	close_program(matrix, "Error\n");
		do_key(key, matrix);
		// print_menu(FDF);
		// frame(matrix);
	}
	// if (key == ONE)
	//     new_window();
	if (key == SPACE)
		close_normal(matrix);
	return (0);
}