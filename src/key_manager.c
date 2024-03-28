/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:07:58 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/28 15:57:43 by ozasahin         ###   ########.fr       */
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
	if (key == PLUS && matrix[0][0].scale < SCALE_FACTOR * 1000)
		matrix[0][0].scale += 0.2 * matrix[0][0].scale;
	if (key == MINUS && matrix[0][0].scale > SCALE_FACTOR)
		matrix[0][0].scale -= 0.2 * abs((int)matrix[0][0].scale) / 2;
	if (key == UP_Z)
		matrix[0][0].depth += 0.5;
	if (key == DOWN_Z)
		matrix[0][0].depth -= 0.5;
	if (key == W)
		matrix[0][0].offset_y += 10;
	if (key == S)
		matrix[0][0].offset_y -= 10;
	if (key == A)
		matrix[0][0].offset_x += 10;
	if (key == D)
		matrix[0][0].offset_x -= 10;
	if (key == DOWN)
		matrix[0][0].rot_x += 0.10;
	if (key == UP)
		matrix[0][0].rot_x -= 0.10;
	if (key == LEFT)
		matrix[0][0].rot_y += 0.10;
	if (key == RIGHT)
		matrix[0][0].rot_y -= 0.10;
}

void	do_mod(int key, t_matrix **matrix)
{
	if (key == Z)
		matrix[0][0].switchs.diagonal *= -1;
	if (key == X)
		matrix[0][0].switchs.gradient *= -1;
	if (key == V)
		matrix[0][0].switchs.isometric *= -1;
}

int	manage_key(int key, t_matrix **matrix)
{
	if (is_key(key) || is_keymod(key))
	{
		mlx_destroy_image(matrix[0][0].mlx, matrix[0][0].imgs.img);
		new_image(matrix);
		if (is_key(key))
			do_key(key, matrix);
		else
			do_mod(key, matrix);
	}
	if (key == SPACE || key == ESC)
		close_normal(matrix);
	return (0);
}
