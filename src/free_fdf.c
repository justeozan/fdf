/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:09:36 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/28 15:32:47 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	clean_close_imgstruct(t_matrix **matrix, t_img imgs)
{
	if (matrix[0][0].mlx)
		mlx_destroy_image(matrix[0][0].mlx, imgs.img);
	imgs.img = NULL;
}

void	free_matrix(t_matrix **matrix)
{
	int	y;

	y = matrix[0][0].height;
	while (--y > 0)
	{
		if (matrix[y])
			free(matrix[y]);
		matrix[y] = NULL;
	}
	if (matrix[0])
		free(matrix[0]);
	if (matrix)
		free(matrix);
	matrix = NULL;
}

int	close_program(t_matrix **matrix, char *txt_err)
{
	if (!matrix[0][0].mlx)
		exit_err(txt_err);
	clean_close_imgstruct(matrix, matrix[0][0].imgs);
	if (matrix[0][0].win)
		mlx_destroy_window(matrix[0][0].mlx, matrix[0][0].win);
	mlx_destroy_display(matrix[0][0].mlx);
	free(matrix[0][0].mlx);
	free_matrix(matrix);
	if (txt_err != NULL)
		exit_err(txt_err);
	ft_printf("closing the program..\n");
	exit(EXIT_SUCCESS);
}

int	close_normal(t_matrix **matrix)
{
	return (close_program(matrix, NULL));
}
