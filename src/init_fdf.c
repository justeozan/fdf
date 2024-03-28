/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:23:20 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/28 15:35:26 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_proj(t_matrix **matrix)
{
	define_switchs(matrix);
	define_scale(matrix);
	define_offset(matrix);
	define_rotation(matrix);
	matrix[0][0].imgs.x_step = 1;
	matrix[0][0].imgs.y_step = 1;
	matrix[0][0].depth = 2.5;
}

t_img	init_new_image(t_matrix	**matrix)
{
	t_img	img;

	ft_bzero(&img, sizeof(t_img));
	img.img = mlx_new_image(matrix[0][0].mlx, WIDTH, HEIGHT);
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
	matrix[0][0].mlx = mlx_init();
	if (!matrix[0][0].mlx)
		close_program(matrix, "Error\n");
	matrix[0][0].win = mlx_new_window(matrix[0][0].mlx, WIDTH, HEIGHT, "fdf");
	if (!matrix[0][0].win)
		close_program(matrix, "Error\n");
	matrix[0][0].imgs = init_new_image(matrix);
	if (mlx_put_image_to_window(matrix[0][0].mlx, matrix[0][0].win,
			matrix[0][0].imgs.img, 0, 0) < 0)
		close_program(matrix, "Error\n");
	init_proj(matrix);
	return (matrix);
}
