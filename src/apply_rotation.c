/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:18:58 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/26 14:25:20 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	apply_rot_x(t_matrix *point, double cos_a, double sin_a)
{
	int	y_old;
	int	z_old;

	y_old = point->y_proj;
	z_old = point->z_proj;
	point->y_proj = y_old * cos_a + z_old * sin_a;
	point->z_proj = y_old * (-sin_a) + z_old * cos_a;
}

void	apply_rot_y(t_matrix *point, double cos_a, double sin_a)
{
	int	x_old;
	int	z_old;

	x_old = point->x_proj;
	z_old = point->z_proj;
	point->x_proj = x_old * cos_a + z_old * (-sin_a);
	point->z_proj = x_old * sin_a + z_old * cos_a;
}

void	apply_rot_z(t_matrix *point, double cos_a, double sin_a)
{
	int	x_old;
	int	y_old;

	x_old = point->x_proj;
	y_old = point->y_proj;
	point->x_proj = x_old * cos_a + y_old * sin_a;
	point->y_proj = x_old * (-sin_a) + y_old * cos_a;
}

void	apply_rotation(t_matrix *point, t_matrix **matrix)
{
	apply_rot_x(point, (double)cos(FDF.rot_x), (double)sin(FDF.rot_x));
	apply_rot_y(point, (double)cos(FDF.rot_y), (double)sin(FDF.rot_y));
	apply_rot_z(point, (double)cos(FDF.rot_z), (double)sin(FDF.rot_z));
}
