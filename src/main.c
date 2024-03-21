/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:07:35 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/21 17:14:05 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	check_args(int ac, char **av)
{
	int	fd;

	if (ac == 2)
	{
		if (!ft_strnstr(av[1], ".fdf", ft_strlen(av[1])))
			ft_print_err("Error! \".fdf\" is needed\n");
		fd = open(av[1], O_RDONLY);
		if (fd <= 0)
			ft_print_err("Error! bad fd or file empty\n");
	}
	else
		ft_printf("Notice : ./fdf <maps.fdf>\n");
	close(fd);
}

int	close_hook(t_matrix **matrix)
{
	// close_program(matrix, NULL);
	// ft_fmxe((void **)matrix, FDF.height, ft_free_matrix, "Shutdown");
	free(FDF.mlx);
	return (0);
}

void	apply_scaling(t_matrix *item, t_matrix **matrix)
{
	item->x_proj = item->x * ceil(FDF.scale);
	item->y_proj = item->y * ceil(FDF.scale);
	item->z_proj = item->z * 0.15 * FDF.scale * FDF.depth;
}

void	apply_offset(t_matrix *item, t_matrix **matrix)
{
	item->x_proj = item->x + FDF.offset_x;
	item->y_proj = item->y + FDF.offset_y;
}

void	init_proj_map(t_matrix **matrix)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while(matrix[y][x].valid) //attention a bien initialiser valid
		{
			apply_scaling(&matrix[y][x], matrix);
			// apply_rotation(matrix);
			apply_offset(&matrix[y][x], matrix);
			x++;
		}
		y++;
	}
}

void	transform_img(t_matrix **matrix)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x].valid)
		{
			if (matrix[y][x + 1].valid)
				ft_printf("1");
				// draw_line(FDF.img, matrix[y][x], matrix[y][x + 1]);
			if (matrix[y + 1])
			{
				if (matrix[y + 1][x].valid)
					ft_printf("2");
				
					// draw_line(FDF.img, matrix[y][x], matrix[y + 1][x]);
				// if (matrix[y + 1][x + 1].valid) //diagnoale
				// 	draw_line(FDF.img, matrix[y][x], matrix[y + 1][x + 1]);
			}
			x++;
		}
		y++;
	}
}

int	frame(t_matrix **matrix)
{
	init_proj_map(matrix);
	transform_img(matrix);
	mlx_put_image_to_window(FDF.mlx, FDF.win, FDF.img->img, 0, 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_matrix	**matrix;

	matrix = NULL;
	check_args(ac, av);
	init_fdf(av[1], matrix);
	mlx_hook(FDF.win, 17, 0, close_hook, matrix);
	// mlx_hook(FDF.win, 2, 1L << 0, manage_keyhook, matrix);
	mlx_loop_hook(FDF.mlx, frame, matrix);
	mlx_loop(FDF.mlx);
	return (0);
}
