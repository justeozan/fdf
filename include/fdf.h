/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:17:47 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/20 16:10:18 by ozasahin         ###   ########.fr       */
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

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

#endif