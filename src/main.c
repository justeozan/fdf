/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:07:35 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/23 16:33:48 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int ac, char **av)
{
	int	fd;

	if (ac == 2)
	{
		if (!ft_strnstr(av[1], ".fdf", ft_strlen(av[1])))
			ft_print_err("Error! \".fdf\" is needed\n");
		// ft_printf("it's a .fdf file all right\n");
		fd = open(av[1], O_RDONLY);
		if (fd <= 0)
			ft_print_err("Error! bad fd or file empty\n");
		// ft_printf("file is not empty, fd = %d\n", fd);
		fdf(av[1]);
	}
	else
		ft_printf("Notice : ./fdf <maps.fdf>\n");
	return (0);
}
