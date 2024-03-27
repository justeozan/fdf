/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:09:36 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/27 16:13:04 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	clean_close_imgstruct(t_matrix **matrix, t_img imgs)
{
	if (FDF.mlx)
		mlx_destroy_image(FDF.mlx, imgs.img);
	imgs.img = NULL;
}

void	free_matrix(t_matrix **matrix)
{
	int	y;

	y = FDF.height;
	while (--y > 0)
	{
		free(matrix[y]);
		matrix[y] = NULL;
	}
	free(matrix);
	matrix = NULL;
}

int	close_program(t_matrix **matrix, char *txt_err)
{
	if (!FDF.mlx)
		exit_err(txt_err);
	clean_close_imgstruct(matrix, FDF.imgs);
	if (FDF.win)
		mlx_destroy_window(FDF.mlx, FDF.win);
	// if (FDF.imgs.addr)
	// 	free(FDF.imgs.addr);
	// if (FDF.mlx)
	mlx_destroy_display(FDF.mlx);
	free(FDF.mlx);
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
