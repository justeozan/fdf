/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:32:08 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/27 15:50:59 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	apply_scaling(t_matrix *point, t_matrix **matrix)
{
	point->x_proj = point->x * ceil(FDF.scale);
	point->y_proj = point->y * ceil(FDF.scale);
	point->z_proj = point->z * 0.05 * FDF.scale * FDF.depth;
}

void	apply_offset(t_matrix *point, t_matrix **matrix)
{
	point->x_proj = point->x_proj + FDF.offset_x;
	point->y_proj = point->y_proj + FDF.offset_y;
}

void	init_proj_map(t_matrix **matrix)
{
	int	x;
	int	y;

	y = 0;
	while (y < FDF.height)
	{
		x = 0;
		while (x < FDF.width)
		{
			apply_scaling(&matrix[y][x], matrix);
			apply_rotation(&matrix[y][x], matrix);
			apply_offset(&matrix[y][x], matrix);
			x++;
		}
		y++;
	}
}

void	transform_img(t_matrix **matrix)
{
	int	x;
	int	y;

	y = 0;
	while (y < FDF.height)
	{
		x = 0;
		while (x < FDF.width)
		{
			if (x + 1 < FDF.width)
			{
				draw_line(FDF.imgs, matrix[y][x], matrix[y][x + 1], M);
			}
			if (y + 1 < FDF.height)
			{
				draw_line(FDF.imgs, matrix[y][x], matrix[y + 1][x], M);
				if (x + 1 < FDF.width && FDF.switchs.diagonal == 1)
					draw_line(FDF.imgs, matrix[y][x], matrix[y + 1][x + 1], M);
			}
			x++;
		}
		y++;
	}
}

int	frame(t_matrix **matrix)
{
	init_proj_map(matrix);
	transform_img(matrix);
	mlx_put_image_to_window(FDF.mlx, FDF.win, FDF.imgs.img, 0, 0);
	return (1);
}