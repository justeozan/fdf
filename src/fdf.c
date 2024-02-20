/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:23:20 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/20 15:37:50 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// void	fdf(char *map)
// {
// 	char	*line;
// 	int		fd;
// 	char	**matrix;
// 	int		i;

// 	i = 0;
// 	fd = open(map, O_RDONLY);
// 	line = get_next_line(map);
// 	matrix[i] = split(line);
// }

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		// check extension .fdf
// 		fdf(av[1]);
// 	}
// 	return (0);
// }

void	draw_line(t_data *data)
{
	int	x;
	int	y;

	x = 100;
	y = 100;
	while (x < 200)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFFFFFF);
		x++;
	}
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "fdf");
	draw_line(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
