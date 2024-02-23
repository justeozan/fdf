/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:11:35 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/23 17:56:27 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_display_tab2d(char **strs)
{
	int	i;
	int	j;

	i = -1;
	while (strs[++i])
	{
		j = -1;
		while (strs[i][++j])
			ft_printf("%c-", strs[i][j]);
		ft_printf("\n");
	}
}



int	get_width(char *line)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && (line[i - 1] == ' ' || i - 1 < 0))
			count++;
		i++;
	}
	return (count);
}

int	get_height(char *file_name)
{
	int	fd;
	int	height;

	fd = open(file_name, O_RDONLY);
	height = 0;
	while (get_next_line(fd))
		height++;
	close(fd);
	return (height);
}
