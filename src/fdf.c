/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:23:20 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/24 12:16:39 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	define_offset(t_matrix **matrix, double scale)
{
	FDF.offset_x = (FDF.width / 2) * scale
		+ round((WIDTH - (scale * FDF.width)) / 2);
	FDF.offset_y = (FDF.height / 2) * scale
		+ round((WIDTH - (scale * FDF.width)) / 2);
}
#include <stdio.h>
void	define_scale(t_matrix **matrix)
{
	double	scale_x;
	double	scale_y;

	//ft_printf("3: scale = %d\n", FDF.scale);
	//printf("scale_x = SCALE_FACTOR * WIDTH / (FDF.width)\n ");
	scale_x = SCALE_FACTOR * WIDTH / (FDF.width);
	scale_y = SCALE_FACTOR * HEIGHT / (FDF.height);
	if (scale_x < scale_y)
		FDF.scale = scale_x;
	else
		FDF.scale = scale_y;
	//printf("4: scale = %f\n", FDF.scale);
}

void	init_proj(t_matrix **matrix)
{
	define_scale(matrix);
	define_offset(matrix, FDF.scale);
	FDF.rot_x = -0.52;
	FDF.rot_y = 0.52;
	FDF.rot_z = 0;
	FDF.depth = 1;
}

t_img	init_new_image(t_matrix	**matrix)
{
	t_img	img;

	ft_bzero(&img, sizeof(t_img));
	img.img = mlx_new_image(FDF.mlx, WIDTH, HEIGHT);
	if (!img.img)
		exit_err("Error, init_new_image");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_len, &img.endian);
	if (!img.addr)
		exit_err("Error, init_new_image");
	return (img);
}

void	set_map(t_matrix **matrix)
{
	FDF.x_proj = 0;
	FDF.y_proj = 0;
	FDF.z_proj = 0;
	FDF.is_isometric = 0;
	FDF.scale = 0;
	FDF.angle = 0;
	FDF.depth = 0;
	FDF.offset_x = 0;
	FDF.offset_y = 0;
	FDF.rot_x = 0;
	FDF.rot_y = 0;
	FDF.rot_z = 0;
}

t_matrix	**init_fdf(char *file_name, t_matrix **matrix)
{
	matrix = get_map(file_name, matrix);
	set_map(matrix);
	display_matrix(matrix, FDF.width, FDF.height);
	FDF.mlx = mlx_init();
	if (!FDF.mlx)
		close_program(matrix, "Error\n");
	FDF.win = mlx_new_window(FDF.mlx, WIDTH, HEIGHT, "fdf");
	if (!FDF.win)
		close_program(matrix, "Error\n");
	FDF.imgs = init_new_image(matrix);
	if (mlx_put_image_to_window(FDF.mlx, FDF.win, FDF.imgs.img, 0, 0) < 0)
		close_program(matrix, "Error\n");
	init_proj(matrix);
	return (matrix);
}
