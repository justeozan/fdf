/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:23:20 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/19 15:45:12 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// void	draw_line(t_fdf *fdf)
// {
// 	int	x;
// 	int	y;

// 	x = 100;
// 	y = 100;
// 	while (x < 200)
// 	{
// 		mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0xFFFFFF);
// 		x++;
// 	}
// }

// void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel/8));
// 	*(unsigned int *)dst = color;
// }

void	define_offset(t_matrix **matrix, double scale)
{
	FDF.offset_x = (FDF.width / 2) * scale
		+ round((WIDTH - (scale * FDF.width)) / 2);
	FDF.offset_y = (FDF.height / 2) * scale
		+ round((WIDTH - (scale * FDF.width)) / 2);
}

void	define_scale(t_matrix **matrix)
{
	double	scale_x;
	double	scale_y;

	scale_x = SCALE_FACTOR * WIDTH / (FDF.width);
	scale_y = SCALE_FACTOR * HEIGHT / (FDF.height);
	if (scale_x < scale_y)
		FDF.scale = scale_x;
	else
		FDF.scale = scale_y;
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
		ft_print_err("Error, init_new_image");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_len, &img.endian);
	if (!img.addr)
		ft_print_err("Error, init_new_image");
	return (img);
}

void	init_fdf(char *file_name, t_matrix **matrix)
{
	matrix = get_map(file_name);
	display_matrix(matrix, (**matrix).width, (**matrix).height);
	ft_free_matrix((void **)matrix, (**matrix).height, &free_mx_data);
	FDF.mlx = mlx_init();
	if (!FDF.mlx)
		ft_fmxe((void **)matrix, (**matrix).height, &free_mx_data, "Error. fdf\n");
	FDF.win = mlx_new_window(FDF.mlx, WIDTH, HEIGHT, "fdf");
	//if error
	FDF.img = init_new_image(matrix);
	if (mlx_put_image_to_window(FDF.mlx, FDF.win, FDF.img.img, 0, 0) < 0)
		ft_fmxe((void **)matrix, (**matrix).height, &free_mx_data, "Error. fdf\n");
	init_proj(matrix);
		
	
	// my_mlx_pixel_put(img.img, 5, 5, 0x00FF0000);
	// draw_line(&fdf);
	mlx_loop(FDF.mlx);
	// free(fdf->mlx);
}
