/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:17:47 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/11 11:56:37 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_matrix
{
	int		x;
	int		y;
	int		z;
}	t_matrix;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	int		z;
}	t_fdf;

/*-------------displays-------------*/
void	display_matrix(t_matrix **matrix, int w, int h);
/*-------------fdf_utils-------------*/
int		get_width(char *line);
int		get_height(char *file_name);
/*-------------fdf-------------*/
// void	fill_matrix(t_fdf ***matrix, char **map);
void	fill_matrix(t_matrix ***matrix, char *file_name, int w, int h);
void	set_size_matrix(t_matrix ***matrix, char *file_name, int *width, int *height);
void	fdf(char *file);
// void	fdf(char *file_name);
/*-------------free_fdf-------------*/
void	free_mx_data(void *ptr);
// void	free_fdf_data(void *ptr);
// void	free2d_exit(t_fdf ***matrix, int height);
/*-------------main-------------*/
// Not needed

/*-------------amandine-------------*/
// t_matrix	**set_size_matrix(char *file_name, int *width, int *height);
// void	free_matrix(t_matrix **matrix, int height);
// void	ft_exit(char *msg, t_matrix **matrix, int height);



#endif