/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:11:35 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/28 15:22:15 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_width(char *line)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && (i == 0 || line[i - 1] == ' '))
			count++;
		i++;
	}
	return (count);
}

int	get_height(int *width, char *file_name)
{
	int		height;
	char	*line;
	int		fd;

	height = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	*width = get_width(line);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	free(line);
	close(fd);
	return (height);
}

char	**extract_first_part(char *s, int *i)
{
	int		j;
	int		k;
	char	**strs;

	strs = (char **)malloc(2 * sizeof(char *));
	if (!strs)
		return (NULL);
	j = 0;
	k = -1;
	while (s[j] && s[j] != ',')
		j++;
	strs[0] = (char *)malloc((j + 1) * sizeof(char));
	if (!strs[0])
		return (free(strs), NULL);
	while (++k < j)
		strs[0][k] = s[k];
	strs[0][j] = 0;
	*i = 0;
	while (s[*i] && s[*i] != ',')
		(*i)++;
	(*i) += 2;
	return (strs);
}

char	*get_color(char *line)
{
	int	i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] != 'x' && line[i])
		line++;
	if (line[i] == 'x')
		line++;
	else
		return (NULL);
	return (line);
}
