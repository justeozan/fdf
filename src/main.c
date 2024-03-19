/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:07:35 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/19 17:03:04 by ozasahin         ###   ########.fr       */
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
	ft_fmxe(matrix, FDF.height, ft_free_matrix, "Shutdown");
	return (0);
}

void	apply_scaling(t_matrix **matrix)
{
	FDF.x_proj = (**matrix).x * ceil(FDF.scale);
	FDF.y_proj = (**matrix).y * ceil(FDF.scale);
	FDF.z_temp = (**matrix).z * 0.15 * FDF.scale * FDF.depth;
}

void	apply_offset(t_matrix **matrix)
{
	FDF.x_proj = (**matrix).x + FDF.offset_x;
	FDF.y_proj = (**matrix).y + FDF.offset_y;
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
			apply_scaling(matrix);
			// apply_rotation(matrix);
			apply_offset(matrix);
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
				draw_line(FDF.img, matrix[y][x], matrix[y][x + 1]);
			if (matrix[y + 1])
			{
				if (matrix[y + 1][x].valid)
					draw_line(FDF.img, matrix[y][x], matrix[y + 1][x]);
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
	mlx_put_image_to_window(FDF.mlx, FDF.win, FDF.img.img, 0, 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_matrix	**matrix;

	check_args(ac, av);
	init_fdf(av[1], matrix);
	mlx_hook(FDF.win, 17, 0, close_hook, matrix);
	// mlx_hook(FDF.win, 2, 1L << 0, manage_keyhook, matrix);
	mlx_loop_hook(FDF.mlx, frame, matrix);
	mlx_loop(FDF.mlx);
	return (0);
}
