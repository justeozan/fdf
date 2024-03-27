/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:07:58 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/27 15:38:43 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	is_key(int key)
{
	return (key == UP || key == DOWN || key == LEFT || key == RIGHT
		|| key == SPACE || key == MINUS || key == PLUS || key == STAR
		|| key == DIV || key == UP_Z || key == DOWN_Z || key == W
		|| key == D || key == S || key == A);
}

int	is_keymod(int key)
{
	return (key == Z || key == X || key == C || key == V);
}

void	do_key(int key, t_matrix **matrix)
{
	if (key == PLUS && FDF.scale < SCALE_FACTOR * 1000)
		FDF.scale += 0.2 * FDF.scale;
	if (key == MINUS && FDF.scale > SCALE_FACTOR)
		FDF.scale -= 0.2 * abs((int)FDF.scale) / 2;
	if (key == UP_Z)
		FDF.depth += 0.5;
	if (key == DOWN_Z)
		FDF.depth -= 0.5;
	if (key == W)
		FDF.offset_y += 10;
	if (key == S)
		FDF.offset_y -= 10;
	if (key == A)
		FDF.offset_x += 10;
	if (key == D)
		FDF.offset_x -= 10;
	if (key == DOWN)
		FDF.rot_x += 0.10;
	if (key == UP)
		FDF.rot_x -= 0.10;
	if (key == LEFT)
		FDF.rot_y += 0.10;
	if (key == RIGHT)
		FDF.rot_y -= 0.10;
}

void	do_mod(int key, t_matrix **matrix)
{
	if (key == Z)
		FDF.switchs.diagonal *= -1;
	if (key == X)
		FDF.switchs.gradient *= -1;
	if (key == V)
	{
		if (FDF.switchs.isometric == 1)
			FDF.switchs.isometric = 0;
		else
			FDF.switchs.isometric = 1;
	}
}

int	manage_key(int key, t_matrix **matrix)
{
	ft_printf("key = %d\n", key);
	if (is_key(key) || is_keymod(key))
	{
		mlx_destroy_image(FDF.mlx, FDF.imgs.img);
		new_image(matrix);
		// if (mlx_put_image_to_window(FDF.mlx, FDF.win, FDF.imgs.img, 0, 0) < 0)
		// 	close_program(matrix, "Error\n");
		if (is_key(key))
			do_key(key, matrix);
		else
			do_mod(key, matrix);
		// print_menu(FDF);
		// frame(matrix);
	}
	// if (key == ONE)
	//     new_window();
	if (key == SPACE)
		close_normal(matrix);
	return (0);
}
