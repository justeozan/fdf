/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:27:47 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/26 11:28:08 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	fill_matrix_old(t_matrix ***matrix, char *file_name, int w, int h)
// {
// 	char	**splitted_line;
// 	int		fd;
// 	int		x;
// 	int		y;
// 	char	*line;

// 	fd = open(file_name, O_RDONLY);
// 	line = get_next_line(fd);
// 	if (!line)
// 		ft_fmxe((void **)matrix, h, &free_mx_data, "Error! (fill_matrix:60)\n");
// 	splitted_line = ft_split(line , ' ');
// 	free(line);
// 	y = 0;
// 	while (splitted_line && y < h)
// 	{
// 		x = -1;
// 		while (++x < w && splitted_line[x])
// 		{
// 			// ft_printf("w=%d\th=%d\tx = %d\ty = %d\tz = -\n", w, h, x, y);
// 			(*matrix)[y][x].x = x;
// 			(*matrix)[y][x].y = y;
// 			(*matrix)[y][x].z = ft_atoi(splitted_line[x]);
// 		}
// 		y++;
// 		ft_freen2d(splitted_line, h);
// 		line = get_next_line(fd);
// 		if (!line)
// 			return ;
// 		splitted_line = ft_split(line, ' ');
// 		free(line);
// 	}
// 	if (y < h - 1 && !splitted_line)
// 	{
// 		ft_freen2d(splitted_line, h);
// 		ft_fmxe((void **)matrix, h, &free_mx_data, "Error! (fill_matrix:85)\n");
// 	}
// 	ft_freen2d(splitted_line, h);
// 	close(fd);
// }

// void	init_matrix(t_fdf fdf)
// {
// 	fdf.mlx_ptr = NULL;
// 	fdf.win_ptr = NULL;
// 	if (fdf.win_ptr)
// 		return ;
// }
