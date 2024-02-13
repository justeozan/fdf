/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:23:20 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/13 19:54:12 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fdf(char *map)
{
	char	*line;
	int		fd;
	char	**matrix;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(map);
	matrix[i] = split(line);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		// check extension .fdf
		fdf(av[1]);
	}
	return (0);
}
