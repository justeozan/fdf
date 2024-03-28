/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:55:46 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/28 15:38:26 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	define_switchs(t_matrix **matrix)
{
	matrix[0][0].switchs.isometric = 1;
	matrix[0][0].switchs.wiggle = 0;
	matrix[0][0].switchs.diagonal = -1;
	matrix[0][0].switchs.gradient = -1;
	matrix[0][0].switchs.bonus = 1;
}

void	define_scale(t_matrix **matrix)
{
	double	scale_y;
	double	scale_x;

	scale_x = (SCALE_FACTOR * WIDTH) / (matrix[0][0].width);
	scale_y = (SCALE_FACTOR * HEIGHT) / (matrix[0][0].height);
	if (scale_x < scale_y)
		matrix[0][0].scale = scale_x;
	else
		matrix[0][0].scale = scale_y;
}

void	define_rotation(t_matrix **matrix)
{
	if (matrix[0][0].switchs.isometric == 1)
	{
		matrix[0][0].rot_x = -0.52;
		matrix[0][0].rot_y = 0.52;
		matrix[0][0].rot_z = 0;
	}
	else
	{
		matrix[0][0].rot_x = 0;
		matrix[0][0].rot_y = 0;
		matrix[0][0].rot_z = 0;
	}
}

void	define_offset(t_matrix **matrix)
{
	matrix[0][0].offset_x = (WIDTH - matrix[0][0].width
			* matrix[0][0].scale) / 2;
	matrix[0][0].offset_y = (HEIGHT - matrix[0][0].height
			* matrix[0][0].scale) / 2;
}
