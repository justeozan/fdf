/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:01:24 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/11 11:52:03 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/fdf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx_linux/mlx.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	int		z;
}	t_data;

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
