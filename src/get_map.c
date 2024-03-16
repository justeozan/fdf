/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:13:03 by marvin            #+#    #+#             */
/*   Updated: 2024/03/16 15:13:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"


t_matrix	**get_map(char file_name)
{
	t_matrix	**matrix;
	int			width;
	int			height;

	matrix = NULL;
	width = 0;
	height = 0;
	set_size_matrix(&matrix, file_name, &width, &height);
	fill_matrix_parent(matrix, file_name, width, height);
	(**matrix).width = width;
	(**matrix).height = height;
	ft_printf("%d, %d", (**matrix).width, (**matrix).height);
	display_matrix(matrix, width, height);
	ft_free_matrix((void **)matrix, height, &free_mx_data);
}