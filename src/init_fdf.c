/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:23:20 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/26 09:58:56 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_proj(t_matrix **matrix)
{
	double	scale_y;
	double	scale_x;

	scale_x = (SCALE_FACTOR * WIDTH) / (FDF.width);
	scale_y = (SCALE_FACTOR * HEIGHT) / (FDF.height);
	if (scale_x < scale_y)
		FDF.scale = scale_x;
	else
		FDF.scale = scale_y;
	FDF.angle = 0.80;
	FDF.is_isometric = 1;
	FDF.offset_x = (WIDTH - FDF.width * FDF.scale) / 2;
	FDF.offset_y = (HEIGHT - FDF.height * FDF.scale) / 2;
	printf("scale = %f, offset_x = %d, offset_y = %d\n", FDF.scale, FDF.offset_x, FDF.offset_y);
	FDF.imgs.x_step = 1;
	FDF.imgs.y_step = 1;
	// FDF.rot_x = -0.52;
	// FDF.rot_y = 0.52;
	// FDF.rot_z = 0;
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

t_matrix	**init_fdf(char *file_name, t_matrix **matrix)
{
	matrix = get_map(file_name, matrix);
	// display_matrix(matrix, FDF.width, FDF.height);
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
