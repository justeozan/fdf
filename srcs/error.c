#include "../include/fdf.h"

void	free_matrix(t_fdf **matrix, int y)
{
	int	i;

	i = 0;
	while (i < y || matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	error_handler(int error, t_fdf **matrix, int y)
{
	if (matrix)
		free_matrix(matrix, y);
	if (error == MALLOC_E)
		ft_error("Error malloc.\n");
	if (error == READ_E)
		ft_error("Error\n Function read fail\n");
	if (error == DIMENSIONS_E)
		ft_error("Error\nInvalid map size.\n");
	
}
void	ft_error(char	*msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

