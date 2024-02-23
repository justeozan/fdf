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

void	display_matrix(t_fdf **matrix, int w, int h)
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
			if (matrix[y][x].z < 10 && !(y >= 10 && x == 0))
				ft_printf("  ");
			else
				ft_printf(" ");
			ft_printf("%d", matrix[y][x].z);
		}
	}
	ft_printf("\n--\n");
}

void	fill_matrix(t_fdf ***matrix, char *file_name, int w, int h)
{
	char	**splitted_line;
	int		fd;
	int		x;
	int		y;

	fd = open(file_name, O_RDONLY);
	y = 0;
	splitted_line = ft_split(get_next_line(fd), ' ');
	while ((splitted_line || y == 0) && y < h)
	{
		x = -1;
		while (splitted_line[++x] && x < w)
		{
			// ft_printf("w=%d\th=%d\tx = %d\ty = %d\tz = -\n", w, h, x, y);
			(*matrix)[y][x].x = x;
			(*matrix)[y][x].y = y;
			(*matrix)[y][x].z = ft_atoi(splitted_line[x]);
		}
		y++;
		ft_free2d(&splitted_line);
		splitted_line = ft_split(get_next_line(fd), ' ');
	}
	if (!splitted_line && y < h - 1)
	{
		ft_free2d(&splitted_line);
		ft_print_err("Error. f2");
	}
	close(fd);
	display_matrix(*matrix, w, h);
}

void	set_size_matrix(t_fdf ***matrix, char *file_name, int *w, int *h)
{
	int	fd;
	int	i;
	
	fd = open(file_name, O_RDONLY);
	*w = get_width(get_next_line(fd));
	close(fd);
	*h = get_height(file_name);
	ft_printf("width = %d\theight = %d\n--\n", *w, *h);
	(*matrix) = (t_fdf **)malloc(sizeof(t_fdf *) * (*h));
	if (!(*matrix))
		return ;
	i = -1;
	while (++i < *h)
	{
		(*matrix)[i] = (t_fdf *)malloc(sizeof(t_fdf) * (*w));
		if (!((*matrix)[i]))
			ft_fmxe_((void ***)matrix, *h, &free_data, "Error. f1\n");
	}
}

void	fdf(char *file_name)
{
	t_fdf	**matrix;
	int		width;
	int		height;

	set_size_matrix(&matrix, file_name, &width, &height);
	// display_matrix(matrix, width, height);
	fill_matrix(&matrix, file_name, width, height);
}
