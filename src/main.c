/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:07:35 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/28 16:10:18 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	check_args(int ac, char **av)
{
	int	fd;

	if (ac == 2)
	{
		if (!ft_strnstr(av[1], ".fdf", ft_strlen(av[1])))
			exit_err("Error! \".fdf\" is needed\n");
		fd = open(av[1], O_RDONLY);
		if (fd <= 0)
			exit_err("Error! bad fd or file empty\n");
	}
	else
		exit_err("Notice : ./fdf <maps.fdf>\n");
	close(fd);
}

int	main(int ac, char **av)
{
	t_matrix	**matrix;

	matrix = NULL;
	check_args(ac, av);
	matrix = init_fdf(av[1], matrix);
	mlx_hook(matrix[0][0].win, 17, 0, close_normal, matrix);
	mlx_hook(matrix[0][0].win, 2, 1L << 0, manage_key, matrix);
	mlx_loop_hook(matrix[0][0].mlx, frame, matrix);
	mlx_loop(matrix[0][0].mlx);
	return (close_program(matrix, NULL));
}
