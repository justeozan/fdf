#include "../include/fdf.h"

void	check_args(int argc, char **argv)
{
	int	pos;
	int	fd;

	if (argc != 2)
		ft_error("Error\n./FDF need a map.\n");
	pos = ft_strlen(argv[1]) - 4;
	if (ft_strcmp(&argv[1][pos], ".fdf") != 0)
		ft_error("Error\nWrong file extension.\n");
	fd = open(argv[1], O_RDONLY);
	if ( fd <= 0)
		ft_error("Error\nCannot open file.\n");
	close (fd);
}

void	setting_data(t_fdf *data)
{
	data->scale = 20;
	data->z_scale = 1;
	data->is_isometric = 1;
	data->angle = 0.523599;
	data->win_x = 2000;
	data->win_y = 1000;
	data->shift_x = (data->win_x - data->width_map) / 2;
	data->shift_y = (data->win_y - data->height_map) / 2;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_x, data->win_y, "FDF");
}

int	on_destroy(t_fdf **matrix)
{
	
	mlx_destroy_window(DATA.mlx_ptr, DATA.win_ptr);
	mlx_destroy_display(DATA.mlx_ptr);
	free(DATA.mlx_ptr);
	free_matrix(matrix, 0);
	exit (EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	**matrix;

	check_args(argc, argv);
	matrix = init_matrix(argv[1]);
	setting_data(&DATA);
	draw_handler(matrix);
	mlx_key_hook(DATA.win_ptr, key_handler, matrix);
	mlx_hook(DATA.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, matrix);
	mlx_loop(DATA.mlx_ptr);
}