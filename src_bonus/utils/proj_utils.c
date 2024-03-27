/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:55:46 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/27 14:58:21 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	define_switchs(t_matrix **matrix)
{
	FDF.switchs.isometric = 0;
	FDF.switchs.wiggle = 0;
	FDF.switchs.diagonal = -1;
	FDF.switchs.gradient = -1;
	FDF.switchs.bonus = 1;
}

void	define_scale(t_matrix **matrix)
{
	double	scale_y;
	double	scale_x;

	scale_x = (SCALE_FACTOR * WIDTH) / (FDF.width);
	scale_y = (SCALE_FACTOR * HEIGHT) / (FDF.height);
	if (scale_x < scale_y)
		FDF.scale = scale_x;
	else
		FDF.scale = scale_y;
}

void	define_rotation(t_matrix **matrix)
{
	if (FDF.switchs.isometric)
	{
		FDF.rot_x = 0;
		FDF.rot_y = 0;
		FDF.rot_z = 0;
	}
	else
	{
		FDF.rot_x = -0.52;
		FDF.rot_y = 0.52;
		FDF.rot_z = 0;
	}
}

void	define_offset(t_matrix **matrix)
{
	FDF.offset_x = (WIDTH - FDF.width * FDF.scale) / 2;
	FDF.offset_y = (HEIGHT - FDF.height * FDF.scale) / 2;
}
