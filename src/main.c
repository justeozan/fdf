/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:07:35 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/25 17:10:25 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// int	main(int ac, char **av)
// {
// 	int	fd;

// 	if (ac == 2)
// 	{
// 		if (!ft_strnstr(av[1], ".fdf", ft_strlen(av[1])))
// 			ft_print_err("Error! \".fdf\" is needed\n");
// 		fd = open(av[1], O_RDONLY);
// 		if (fd < 0)
// 			ft_print_err("Error! bad fd or file empty\n");
// 		fdf(av[1]);
// 	}
// 	else
// 		ft_printf("Notice : ./fdf <maps.fdf>\n");
// 	close(fd);
// 	return (0);
// }

int main(int ac, char **av)
{
	char	**split;
	char	*line;
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		line = get_next_line(fd);
		split = ft_split(line, ' ');
	}
	ft_free2d(&split);
	free(line);
	return (0);
}
