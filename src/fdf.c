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

char	**line_parser(char *line)
{
	char	**splitted_line;

	if (!line)
		return (NULL);
	splitted_line = ft_split(line, ' ');
	free (line);
	return (splitted_line);
}

void	fill_matrix_children(t_matrix **matrix, char **line2d, int w, int y)
{
	int	x;

	x = -1;
	if (!line2d | !(*line2d))
		return (ft_fmxe((void **)matrix, y, free_mx_data, "Error\n"));
	while (++x < w)
	{
		matrix[y][x].x = x;
		matrix[y][x].y = y;
		matrix[y][x].z = ft_atoi(line2d[x]);
	}
	ft_free2d(line2d);
}

void	fill_matrix_parent(t_matrix **matrix, char *f_name, int w, int h)
{
	int	fd;
	int	y;

	fd = open(f_name, O_RDONLY);
	if (fd < 1)
		ft_fmxe((void **)matrix, h, &free_mx_data, "Error\n");
	y = -1;
	while (++y < h)
		fill_matrix_children(matrix, line_parser(get_next_line(fd)), w, y);
}

void	set_size_matrix(t_matrix ***matrix, char *file_name, int *w, int *h)
{
	int	fd;
	int	i;
	
	fd = -1;
	fd = open(file_name, O_RDONLY);
	if (fd < 1)
		ft_print_err("Error. f1\n");
	*w = get_width(get_next_line(fd));
	close(fd);
	*h = get_height(file_name);
	if (*w < 0 || *h < 0)
		ft_print_err("Error. f1\n");
	(*matrix) = (t_matrix **)malloc(sizeof(t_matrix *) * (*h));
	if (!(*matrix))
		ft_fmxe((void **)matrix, *h, &free_mx_data, "Error. f1\n");
	i = -1;
	while (++i < *h)
	{
		(*matrix)[i] = (t_matrix *)malloc(sizeof(t_matrix) * (*w));
		if (!((*matrix)[i]))
			ft_fmxe((void **)matrix, *h, &free_mx_data, "Error. f1\n");
	}
}

void	draw_line(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 100;
	y = 100;
	while (x < 200)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xFFFFFF);
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
	int			width;
	int			height;
	//
	t_img		img;

	matrix = NULL;
	width = 0;
	height = 0;

	set_size_matrix(&matrix, file_name, &width, &height);
	fill_matrix_parent(matrix, file_name, width, height);
	// display_matrix(matrix, width, height);
	ft_free_matrix((void **)matrix, height, &free_mx_data);
	// -------------------------------
	//test
	fdf.mlx_ptr = mlx_init();
	if (!fdf.mlx_ptr)
			ft_fmxe((void **)matrix, height, &free_mx_data, "Error. fdf\n");
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, WIDTH, HEIGHT, "fdf");
	img.img = mlx_new_image(fdf.mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(img.img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, img.img, 0, 0);
	//
	//
	// draw_line(&fdf);
	mlx_loop(fdf.mlx_ptr);
	// --------------------------------
	// free(fdf->mlx_ptr);
}
