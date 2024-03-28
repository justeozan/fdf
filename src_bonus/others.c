/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:36:57 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/28 15:38:07 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	new_image(t_matrix **matrix)
{
	matrix[0][0].imgs.img = mlx_new_image(matrix[0][0].mlx, WIDTH, HEIGHT);
	matrix[0][0].imgs.addr = mlx_get_data_addr(matrix[0][0].imgs.img,
			&matrix[0][0].imgs.bits_per_pixel, &matrix[0][0].imgs.line_len,
			&matrix[0][0].imgs.endian);
}

// void	ft_display_tab2d(char **strs)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (strs[++i])
// 	{
// 		j = -1;
// 		while (strs[i][++j])
// 			ft_printf("%c-", strs[i][j]);
// 		ft_printf("\n");
// 	}
// 	// ft_free2d(&strs);
// }

// void	draw_black(t_matrix **matrix)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < HEIGHT)
// 	{
// 		x = 0;
// 		while (x < WIDTH)
// 		{
// 			put_pixel(FDF.imgs, x, y, 0);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	display_matrix(t_matrix **matrix, int w, int h)
// {
// 	int	x;
// 	int	y;

// 	ft_printf("--\nwidth = %d, height = %d\n--\n", FDF.width, FDF.height);
// 	if (!matrix || !(*matrix) || w < 0 || h < 0)
// 		exit_err("Error! display_matrix: matrix is NULL\n");
// 	ft_printf(" ");
// 	x = -1;
// 	while (++x < w)
// 		(x < 10) ? ft_printf("  %d", x): ft_printf(" %d", x);
// 	y = -1;
// 	while (++y < h)
// 	{
// 		ft_printf("\n%d", y);
// 		x = -1;
// 		while (++x < w)
// 		{
// 			if (!(y >= 10 && x == 0) && matrix[y][x].z < 10)
// 				ft_printf("  %d", matrix[y][x].z);
// 			else
// 				ft_printf(" %d", matrix[y][x].z);
// 		}
// 	}
// 	ft_printf("\n--\n");
// }
