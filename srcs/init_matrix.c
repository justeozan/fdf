#include "../include/fdf.h"

int	filling_matrix(char *line, t_fdf **matrix, int y)
{
	char	**values;
	int		x;

	values = ft_split(line, ' ');
	if (!values)
		return (MALLOC_E);
	x = 0;
	while (values[x] != NULL)
	{
		matrix[y][x].z = ft_atoi(values[x]);
		matrix[y][x].x = x;
		matrix[y][x].y = y;
		matrix[y][x].is_last = 0;
		free(values[x]);
		x++;
	}
	free(values);
	matrix[y][--x].is_last = 1;
	return (x);
}

void	calculates_size_matrix(char *filename, int *x,	int *y)
{
	int		fd;
	char	*line;
	int		octets;

	fd = open(filename, O_RDONLY);
	octets = 1;
	while (octets > 0)
	{
		octets = get_next_line_octet(fd, &line);
		if (octets > 0)
		{
			if (*x == 0)
				*x = words_counter(line, ' ');
			(*y)++;
			free(line);
		}
	}
	close (fd);
	if (line)
		free(line);
	if (octets < 0)
		error_handler(octets, NULL, 0);
}

t_fdf	**memory_allocation(char *filename)
{
	t_fdf	**matrix;
	int		height;
	int		width;
	int		i;

	width = 0;
	height = 0;
	calculates_size_matrix(filename, &width, &height);
	if (height <= 0 || width <= 0)
		error_handler(DIMENSIONS_E, NULL, 0);
	matrix = (t_fdf **)malloc((height + 1) * sizeof(t_fdf *));
	if (!matrix)
		error_handler(MALLOC_E, NULL, 0);
	i = 0;
	while (i < height)
	{
		matrix[i] = (t_fdf *)malloc((width + 1) * sizeof(t_fdf));
		if (!matrix[i])
			error_handler(MALLOC_E, matrix, i);
		i++;
	}
	DATA.width_map = width;
	DATA.height_map = height;
	matrix[i] = NULL;
	return (matrix);
}

t_fdf	**init_matrix(char *filename)
{
	t_fdf	**matrix;
	int		y;
	int		fd;
	int		octets;
	char	*line;

	matrix = memory_allocation(filename);
	fd = open(filename, O_RDONLY);
	y = 0;
	octets = 1;
	while (octets > 0)
	{
		octets = get_next_line(fd, &line);
		if (octets > 0)
		{
			octets = filling_matrix(line, matrix, y++);
			free(line);
		}
	}
	if (line)
		free(line);
	close(fd);
	if (octets < 0)
		error_handler(octets, matrix, 0);
	return (matrix);
}