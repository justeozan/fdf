/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:36:57 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/26 11:37:27 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	display_matrix(t_matrix **matrix, int w, int h)
{
	int	x;
	int	y;

	if (!matrix || !(*matrix) || w < 0 || h < 0)
		ft_print_err("Error! display_matrix: matrix is NULL\n");
	ft_printf(" ");
	x = -1;
	while (++x < w)
	{
		if (x < 10)
			ft_printf("  %d", x);
		else
			ft_printf(" %d", x);
	}
	y = -1;
	while (++y < h)
	{
		ft_printf("\n%d", y);
		x = -1;
		while (++x < w)
		{
			if (!(y >= 10 && x == 0) && matrix[y][x].z < 10)
				ft_printf("  ");
			else
				ft_printf(" ");
			ft_printf("%d", matrix[y][x].z);
		}
	}
	ft_printf("\n--\n");
	// ft_free_matrix((void **)matrix, h, &free_mx_data);
}
