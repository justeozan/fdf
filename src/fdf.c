/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:23:20 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/26 11:37:20 by ozasahin         ###   ########.fr       */
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

void	fill_matrix_children(t_matrix **matrix, char **splitted_line, int w, int y)
{
	int	x;
	
	x = 0;
	if (!splitted_line | !(*splitted_line))
		return (ft_fmxe((void **)matrix, y, free_mx_data, "Error\n"));
	while (x < w)
	{
		matrix[y][x].x = x;
		matrix[y][x].y = y;
		matrix[y][x].z = ft_atoi(splitted_line[x]);
	}
	ft_free2d(&splitted_line);
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
	char *line;
	int	i;
	
	fd = -1;
	// if (!matrix || !(*matrix))
	// 	ft_print_err("Error. f1\n");
	fd = open(file_name, O_RDONLY);
	if (fd < 1)
		ft_print_err("Error. f1\n");
	line = get_next_line(fd);
	if (!line)
		
	*w = get_width(line);
	close(fd);
	*h = get_height(file_name);
	if (*w < 0 || *h < 0)
		ft_print_err("Error. f1\n");
	// ft_printf("width = %d\theight = %d\n--\n", *w, *h);
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
	fill_matrix_parent(matrix, file_name, width, height);
	display_matrix(matrix, width, height);
	ft_free_matrix((void **)matrix, height, &free_mx_data);
}
