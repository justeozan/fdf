/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:13:03 by marvin            #+#    #+#             */
/*   Updated: 2024/03/27 11:05:15 by ozasahin         ###   ########.fr       */
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
	char **values;

	x = -1;
	if (!line2d | !(*line2d))
		close_program(matrix, "Error\n");
	while (++x < w)
	{
		matrix[y][x].x = x;
		matrix[y][x].y = y;
		values = ft_split_color(line2d[x]);
		if (!values || !values[0])
			return (ft_free2d(values));
		matrix[y][x].z = ft_atoi(values[0]);
		matrix[y][x].color = ft_atoi_base(values[1], "0123456789abcdef");
		// ft_printf("color = %d\n", matrix[y][x].color);
	}
	ft_free2d(line2d);
	ft_free2d(values);
}

void	fill_matrix_parent(t_matrix **matrix, char *f_name)
{
	int	fd;
	int	y;

	fd = open(f_name, O_RDONLY);
	if (fd < 1)
		close_program(matrix, "Error\n");
	y = -1;
	// ft_printf("Tout est ok, y = , height = %d\n", FDF.height);
	while (++y < FDF.height)
	{
		fill_matrix_children(matrix, line_parser(get_next_line(fd)), FDF.width, y);
	}
}

void	set_size_matrix(t_matrix ***matrix, char *file_name, int w, int h)
{
	int	fd;
	int	i;
	
	fd = -1;
	fd = open(file_name, O_RDONLY);
	if (fd < 1)
		exit_err("Error. f1\n");
	w = get_width(get_next_line(fd));
	close(fd);
	h = get_height(file_name);
	if (w < 0 || h < 0)
		exit_err("Error. f1\n");
	*matrix = (t_matrix **)malloc(sizeof(t_matrix *) * (h));
	if (!(*matrix))
		close_program(*matrix, "Error\n");
	i = -1;
	while (++i < h)
	{
		(*matrix)[i] = (t_matrix *)malloc(sizeof(t_matrix) * (w + 1));
		if (!(*matrix)[i])
			close_program(*matrix, "Error\n");
	}
	FDF->width = w;
	FDF->height = h;
}

t_matrix	**get_map(char *file_name, t_matrix **matrix)
{
	set_size_matrix(&matrix, file_name, 0, 0);
	fill_matrix_parent(matrix, file_name);
	FDF.center_x = FDF.width / 2;
	FDF.center_y = FDF.height / 2;

	return (matrix);
}
