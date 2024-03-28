/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:32:08 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/28 15:36:40 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	apply_scaling(t_matrix *point, t_matrix **matrix)
{
	point->x_proj = point->x * ceil(matrix[0][0].scale);
	point->y_proj = point->y * ceil(matrix[0][0].scale);
	point->z_proj = point->z * 0.05 * matrix[0][0].scale * matrix[0][0].depth;
}

void	apply_offset(t_matrix *point, t_matrix **matrix)
{
	point->x_proj = point->x_proj + matrix[0][0].offset_x;
	point->y_proj = point->y_proj + matrix[0][0].offset_y;
}

void	init_proj_map(t_matrix **matrix)
{
	int	x;
	int	y;

	y = 0;
	while (y < matrix[0][0].height)
	{
		x = 0;
		while (x < matrix[0][0].width)
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
	while (y < matrix[0][0].height)
	{
		x = 0;
		while (x < matrix[0][0].width)
		{
			if (x + 1 < matrix[0][0].width)
			{
				draw_line(matrix[0][0].imgs, matrix[y][x], matrix[y][x + 1], M);
			}
			if (y + 1 < matrix[0][0].height)
			{
				draw_line(matrix[0][0].imgs, matrix[y][x], matrix[y + 1][x], M);
				if (x + 1 < matrix[0][0].width &&
					matrix[0][0].switchs.diagonal == 1)
					draw_line(matrix[0][0].imgs, matrix[y][x],
						matrix[y + 1][x + 1], M);
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
	mlx_put_image_to_window(matrix[0][0].mlx, matrix[0][0].win,
		matrix[0][0].imgs.img, 0, 0);
	return (1);
}
