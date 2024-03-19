/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:10:59 by marvin            #+#    #+#             */
/*   Updated: 2024/03/19 18:46:49 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_param(t_matrix *a, t_matrix *b, t_matrix *data)
{
	zoom(a, b, data);
	if (data->is_isometric)
	{
		isometric(a, data->angle);
		isometric(b, data->angle);
	}
	a->x += data->shift_x;
	a->y += data->shift_y;
	b->x += data->shift_x;
	b->y += data->shift_y;
}

void	bresenham(t_matrix a, t_matrix b, t_matrix *data)
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
		mlx_pixel_put(data->mlx, data->win, a.x, a.y, 250);
		a.x += step_x;
		a.y += step_y;
		if (a.x > data->width || a.y > data->height || a.y < 0 || a.x < 0)
			break;
	}
}

void	draw_line_h(t_img img, t_matrix m0, t_matrix m1)
{
	img.x_step = 1;
	img.y_step = 1;
	img.x_diff = abs(m1.x_proj - m0.x_proj);
	img.y_diff = abs(m1.y_proj - m0.y_proj);
	if (m1.x_proj <= m0.x_proj)
		img.x_step = -1;
	if (m1.y_proj <= m0.y_proj)
		img.y_step = -1;
	
	if (img.x_diff > img.y_diff)
	{
		img.decision = 2 * img.y_diff - img.x_diff;
	}
}

void	draw_line_g(t_matrix **matrix)
{
	int	y;
	int	x;

	// print_menu(FDF);
	y = 0;
	while (matrix[y] != NULL)
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				bresenham(matrix[y][x], matrix[y + 1][x], &FDF);
			if (!matrix[y][x].is_last) //is_last = valid
				bresenham(matrix[y][x], matrix[y][x + 1], &FDF);
			if (matrix[y][x].is_last) //is last = valid
				break;
			x++;
		}
		y++;
	}

}