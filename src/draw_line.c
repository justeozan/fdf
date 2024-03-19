/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:10:59 by marvin            #+#    #+#             */
/*   Updated: 2024/03/19 17:13:55 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"



void	draw_line(t_img img, t_matrix m0, t_matrix m1)
{
	img.x_step = 1;
	img.y_step = 1;
	img.x_diff = abs(m1.x_proj - m0.x_proj);
	img.y_diff = abs(m1.y_proj - m0.y_proj);
	if (m1.x_proj <= m0.x_proj)
		img.x_step = -1;
	if (m1.y_proj <= m0.y_proj)
		img.y_step = -1;
	
	if (img.x_diff > img.y_diff)
	{
		img.decision = 2 * img.y_diff - img.x_diff;
	}
}