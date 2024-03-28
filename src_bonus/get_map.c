/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:13:03 by marvin            #+#    #+#             */
/*   Updated: 2024/03/28 15:32:59 by ozasahin         ###   ########.fr       */
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

int	fill_matrix_children(t_matrix **matrix, char **line2d, int w, int y)
{
	int		no_color;
	int		x;

	no_color = 0;
	x = -1;
	while (++x < w)
	{
		matrix[y][x].x = x;
		matrix[y][x].y = y;
		matrix[y][x].z = ft_atoi(line2d[x]);
		if (matrix[y][x].z > 10000 || matrix[y][x].z < -10000)
			close_program(matrix, "Error\n");
		matrix[y][x].color = ft_atoi_base(get_color(line2d[x]),
				"0123456789abcdef");
		if (matrix[y][x].color != 0xFFFFFF && matrix[y][x].color != -1)
			no_color = 1;
	}
	if (no_color == 0)
		add_color(matrix);
	ft_free2d(line2d);
	return (no_color);
}

void	fill_matrix_parent(t_matrix **matrix, char *f_name)
{
	int		fd;
	int		y;
	char	**line2d;

	fd = open(f_name, O_RDONLY);
	if (fd < 1)
		close_program(matrix, "Error\n");
	y = -1;
	while (++y < matrix[0][0].height)
	{
		line2d = line_parser(get_next_line(fd));
		if (!line2d)
			close_program(matrix, "Error\n");
		fill_matrix_children(matrix, line2d, matrix[0][0].width, y);
	}
}

void	set_size_matrix(t_matrix ***matrix, char *file_name, int w, int h)
{
	int	i;

	h = get_height(&w, file_name);
	if (w < 0 || h < 0)
		close_program(*matrix, "Error\n");
	*matrix = (t_matrix **)ft_calloc(h, sizeof(t_matrix *));
	if (!(*matrix))
		close_program(*matrix, "Error\n");
	i = -1;
	while (++i < h)
	{
		(*matrix)[i] = (t_matrix *)ft_calloc(w, sizeof(t_matrix));
		if (!(*matrix)[i])
			close_program(*matrix, "Error\n");
	}
	matrix[0][0]->width = w;
	matrix[0][0]->height = h;
}

t_matrix	**get_map(char *file_name, t_matrix **matrix)
{
	set_size_matrix(&matrix, file_name, 0, 0);
	fill_matrix_parent(matrix, file_name);
	matrix[0][0].center_x = matrix[0][0].width / 2;
	matrix[0][0].center_y = matrix[0][0].height / 2;
	return (matrix);
}
