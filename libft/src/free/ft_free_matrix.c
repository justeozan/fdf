/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:25:31 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/23 16:08:29 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

// matrix is 2d tab of structure
void	ft_free_matrix(void ***matrix, int height, void (*free_func)(void *))
{
	int	i;

	i = 0;
	while (i < height)
	{
		free_func((*matrix)[i++]);
	}
	free(*matrix);
	(*matrix) = NULL;
}

// With Comments
void	ft_free_matrix_(void ***matrix, int height, void (*free_func)(void *))
{
	int	i;

	i = 0;
	ft_printf("--\nTry to free 2d structure:\n");
	while (i < height)
	{
		free_func((*matrix)[i++]);
		ft_printf("matrix[%d] = %s\n", i - 1, (char *)(*matrix)[i]);
	}
	free(*matrix);
	(*matrix) = NULL;
	ft_printf("matrix = %s\n", (char **)(*matrix));
}

// fmxe = free matrix and error
void	ft_fmxe(void ***matrix, int h, void (*f)(void *), char *err_txt)
{
	ft_free_matrix(matrix, h, f);
	ft_print_err(err_txt);
}

// With comments
void	ft_fmxe_(void ***matrix, int h, void (*f)(void *), char *err_txt)
{
	ft_free_matrix_(matrix, h, f);
	ft_print_err(err_txt);
}
