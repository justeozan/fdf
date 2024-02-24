/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:23:20 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/23 19:25:43 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	display_matrix(t_matrix **matrix, int w, int h)
{
	int	x;
	int	y;

	x = -1;
	ft_printf(" ");
	while (++x < w)
	{
		if (x < 10)
			ft_printf("  %d", x);
		else
			ft_printf(" %d", x);
	}
	y = -1;
	while (++y < h)
	{
		ft_printf("\n%d", y);
		x = -1;
		while (++x < w)
		{
			if (!(y >= 10 && x == 0) && matrix[y][x].z < 10)
				ft_printf("  ");
			else
				ft_printf(" ");
			ft_printf("%d", matrix[y][x].z);
		}
	}
	ft_printf("\n--\n");
	ft_free_matrix((void ***)&matrix, h, &free_mx_data);
}

void	fill_matrix(t_matrix ***matrix, char *file_name, int w, int h)
{
	char	**splitted_line;
	int		fd;
	int		x;
	int		y;
	char	*line;

	fd = open(file_name, O_RDONLY);
	y = 0;
	line = get_next_line(fd);
	splitted_line = ft_split(line , ' ');
	free(line);
	while ((splitted_line || y == 0) && y < h)
	{
		x = -1;
		while (x < w && splitted_line[++x])
		{
			// ft_printf("w=%d\th=%d\tx = %d\ty = %d\tz = -\n", w, h, x, y);
			(*matrix)[y][x].x = x;
			(*matrix)[y][x].y = y;
			(*matrix)[y][x].z = ft_atoi(splitted_line[x]);
		}
		y++;
		ft_free2d(&splitted_line);
		line = get_next_line(fd);
		splitted_line = ft_split(line, ' ');
		free(line);
	}
	if (y < h - 1 && !splitted_line)
	{
		ft_free2d(&splitted_line);
		ft_print_err("Error. f2");
	}
	// if (splitted_line)
	// 	ft_free2d(&splitted_line);
	close(fd);
	// display_matrix(*matrix, w, h);
	// free(splitted_line);
	// splitted_line = NULL;
}

void	set_size_matrix(t_matrix ***matrix, char *file_name, int *w, int *h)
{
	int	fd;
	int	i;
	
	fd = -1;
	if (!matrix || !(*matrix))
		return ;
	fd = open(file_name, O_RDONLY);
	if (fd < 1)
		ft_print_err("Error. f1");
	*w = get_width(get_next_line(fd));
	close(fd);
	*h = get_height(file_name);
	if (*w < 0 || *h < 0)
		return ;
	// ft_printf("width = %d\theight = %d\n--\n", *w, *h);
	(*matrix) = (t_matrix **)malloc(sizeof(t_matrix *) * (*h));
	if (!(*matrix))
		ft_fmxe((void ***)matrix, *h, &free_mx_data, "Error. f1\n");
	i = -1;
	while (++i < *h)
	{
		(*matrix)[i] = (t_matrix *)malloc(sizeof(t_matrix) * (*w));
		if (!((*matrix)[i]))
			ft_fmxe((void ***)matrix, *h, &free_mx_data, "Error. f1\n");
	}
	return ;
}

// void	init_matrix(t_fdf fdf)
// {
// 	fdf.mlx_ptr = NULL;
// 	fdf.win_ptr = NULL;
// 	if (fdf.win_ptr)
// 		return ;
// }

void	fdf(char *file_name)
{
	t_matrix	**matrix;
	// t_fdf		fdf;
	int			width;
	int			height;

	// init_matrix(fdf);
	matrix = NULL;
	width = 0;
	height = 0;
	set_size_matrix(&matrix, file_name, &width, &height);
	// display_matrix(matrix, width, height);
	fill_matrix(&matrix, file_name, width, height);
	ft_free_matrix((void ***)&matrix, height, &free_mx_data);
	// return ;
}
