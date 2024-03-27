/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:09:36 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/25 11:38:25 by ozasahin         ###   ########.fr       */
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
/*
int	close_program(t_fdf *p_fdf, char *strerr) //hugo
{
	if (!p_fdf->mlx)
		exit_error(strerr);
	clean_close_imgstruct(p_fdf, &(p_fdf->s_img_to_del));
	clean_close_imgstruct(p_fdf, &(p_fdf->s_new_img));
	if (&(p_fdf->win))
		mlx_destroy_window(p_fdf->mlx, p_fdf->win);
	free_map_elem2(&(p_fdf->map));
	mlx_destroy_display(p_fdf->mlx);
	free(p_fdf->mlx);
	if (strerr)
		exit_error(strerr);
	exit(EXIT_SUCCESS);
}
*/
int	close_normal(t_matrix **matrix)
{
	return (close_program(matrix, NULL));
}
// void	free_mx_data(void *ptr)
// {
// 	free(ptr);
// }




// void	free_fdf_data(void *ptr)
// {
// 	t_fdf	*data;

// 	data = (t_fdf *)ptr;
// 	if (data)
// 	{
// 		if (data->mlx_ptr)
// 			free(data->mlx_ptr);
// 		if (data->win_ptr)
// 			free(data->win_ptr);
// 		free(data);
// 	}
// 	free(ptr);
// }

// void	free2d_exit(t_fdf ***matrix, int height)
// {
// 	ft_free_matrix((void ***)matrix, height, &free_data);
// 	ft_print_err("Error. Stoped.\n");
// }
