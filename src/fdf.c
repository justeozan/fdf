/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:23:20 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/21 17:59:31 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_height(char *file_name)
{
	int	fd;
	int	height;

	fd = open(file_name, O_RDONLY);
	height = 0;
	while (get_next_line_octet(fd, NULL))
		height++;
	close(fd);
	return (height);
}

void	set_size_matrix(t_data *matrix, char *file_mame)
{
	// int	octet;
	// int	y;
	int	height;
	
	// y = 0;
	height = get_height(file_mame);
	free(matrix);
	ft_printf("height = %d", height);
	// octet = get_next_line_octet(fd);
	// while (octet > 0)
	// {
	// 	octet = get_next_line_octet(fd);
	// 	y++;
	// }
}

void	fdf(char *file_name)
{
	t_data	*matrix;

	matrix = (t_data *)malloc(sizeof(t_data));
	if (!matrix)
		return ;
	set_size_matrix(matrix, file_name);
}

int	main(int ac, char **av)
{
	int	fd;

	if (ac == 2)
	{
		if (!ft_strnstr(av[1], ".fdf", ft_strlen(av[1])))
			ft_print_err("Error! \".fdf\" is needed\n");
		ft_printf("it's a .fdf file all right\n");
		fd = open(av[1], O_RDONLY);
		if (fd <= 0)
			ft_print_err("Error! bad fd or file empty\n");
		ft_printf("file is not empty, fd = %d\n", fd);
		fdf(av[1]);
	}
	else
		ft_printf("Notice : ./fdf <maps.fdf>\n");
	return (0);
}
