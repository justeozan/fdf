/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:23:20 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/11 12:00:08 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"







void	draw_line(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 100;
	y = 100;
	while (x < 200)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0xFFFFFF);
		x++;
	}
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel/8));
	*(unsigned int *)dst = color;
}

void	fdf(char *file_name)
{
	t_matrix	**matrix;
	t_fdf		fdf;
	t_img		img;

	matrix = get_map(file_name);
	display_matrix(matrix, (**matrix).width, (**matrix).height);
	ft_free_matrix((void **)matrix, (**matrix).height, &free_mx_data);
	// -------------------------------
	fdf.mlx = mlx_init();
	if (!fdf.mlx)
		ft_fmxe((void **)matrix, (**matrix).height, &free_mx_data, "Error. fdf\n");
	fdf.win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "fdf");
	img.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(img.img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(fdf.mlx, fdf.win, img.img, 0, 0);
	//
	//
	// draw_line(&fdf);
	// mlx_loop(fdf.mlx);
	// --------------------------------
	// free(fdf->mlx);
}
