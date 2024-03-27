/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:11:35 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/26 16:33:58 by ozasahin         ###   ########.fr       */
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
	// ft_free2d(&strs);
}

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
	free(line);
	return (count);
}

int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY);
	height = 0;
	line = get_next_line(fd);
	// line = get_next_line(fd, &line);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
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
		return (NULL);
	while (++k < j)
		strs[0][k] = s[k];
	strs[0][j] = 0;
	*i = 0;
	while (s[*i] && s[*i] != ',')
		(*i)++;
	(*i) += 2;
	return (strs);
}

char	**ft_split_color(char *s)
{
	char	**strs;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	strs = extract_first_part(s, &i);
	if (!strs || !strs[0])
		return (ft_free2d(strs), NULL);
	if (ft_strnstr_2(s, ",0x", 3))
	{
		strs[1] = (char *)malloc((ft_strlen(s) - i + 1) * sizeof(char));
		if (!strs[1])
			return (ft_free2d(strs), NULL);
		j = 0;
		while (s[++i])
		{
			strs[1][j] = s[i];
			j++;
		}
		strs[1][j] = 0;
	}
	else
		strs[1] = NULL;
	return (strs);
}