/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:07:58 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/25 16:43:59 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int is_key(int key)
{
	return(key == PLUS || key == MINUS);
}

void    do_key(int key, t_matrix **matrix)
{
	if (key == PLUS)
		FDF.scale += 3;
	if (key == MINUS)
		FDF.scale -= 3;
}

void	draw_black(t_matrix **matrix)
{
	int	x;
	int	y;

	y = 0;
	while (y < FDF.height)
	{
		x = 0;
		while (x < FDF.width)
		{
			put_pixel(FDF.imgs, x, y, 0);
			x++;
		}
		y++;
	}
}


int    manage_key(int key, t_matrix **matrix)
{
	ft_printf("key = %d\n", key);
	if (is_key(key))
	{
		draw_black(matrix);
		mlx_put_image_to_window(FDF.mlx, FDF.win, FDF.imgs.img, 0, 0);
		// if (mlx_put_image_to_window(FDF.mlx, FDF.win, FDF.imgs.img, 0, 0) < 0)
		// 	close_program(matrix, "Error\n");
		do_key(key, matrix);
		// print_menu(FDF);
		frame(matrix);
	}
	// if (key == ONE)
	//     new_window();
	if (key == SPACE)
		close_normal(matrix);
	return (0);
}