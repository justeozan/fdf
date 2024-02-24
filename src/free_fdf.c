/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:09:36 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/23 16:40:44 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_mx_data(void *ptr)
{
	free(ptr);
}

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
