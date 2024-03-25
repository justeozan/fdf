/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:10:59 by marvin            #+#    #+#             */
/*   Updated: 2024/03/25 13:16:22 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	put_pixel(t_img imgs, int x, int y, int color)
{
	int	offset;

	offset = (imgs.line_len * y) + (imgs.bits_per_pixel * x / 8);
	if (x >= 0 && x < WIDTH && y > 0 && y < HEIGHT)
		*((int *)(imgs.addr + offset)) = color;
	
}

void	draw_acute_slope(t_img imgs, t_matrix m0, t_matrix m1)
{
	while (m0.x_proj != m1.x_proj)
	{
		if (m0.x_proj >= 0 && m0.x_proj < WIDTH && m0.y_proj > 0 && m0.y_proj < HEIGHT)
			put_pixel(imgs, m0.x_proj, m0.y_proj, m0.color);
		m0.x_proj += imgs.x_step;
		if (imgs.decision <= 0)
			imgs.decision = 2 * imgs.y_diff;
		else
		{
			m0.y_proj += imgs.y_step; //y_diff
			imgs.decision = 2 * (imgs.y_diff - imgs.x_diff);
		}
	}
}

void	draw_obtus_slope(t_img imgs, t_matrix m0, t_matrix m1)
{
	// int nb_step;
	
	// nb_step = 0;
	while (m0.x_proj != m1.x_proj)
	{
		if (m0.x_proj >= 0 && m0.x_proj < WIDTH && m0.y_proj > 0 && m0.y_proj < HEIGHT)
			put_pixel(imgs, m0.x_proj, m0.y_proj, m0.color);
		m0.y_proj += imgs.y_step;
		if (imgs.decision <= 0)
			imgs.decision = 2 * imgs.x_diff;
		else
		{
			m0.x_proj += imgs.x_diff;
			imgs.decision = 2 * (imgs.x_diff - imgs.y_diff);
		} 
		// nb_step++;
	}
}

void	init_step(t_img *imgs, t_matrix *m0, t_matrix *m1)
{
	imgs->x_diff = abs(m1->x_proj - m0->x_proj);
	imgs->y_diff = abs(m1->y_proj - m0->y_proj);
	if (m1->x_proj > m0->x_proj)
		imgs->x_step = 1;
	else
		imgs->x_step = -1;
	if (m1->y_proj > m0->y_proj)
		imgs->y_step = 1;
	else
		imgs->y_step = -1;
}

void	draw_line(t_img imgs, t_matrix m0, t_matrix m1)
{
	init_step(&imgs, &m0, &m1); 
	if (imgs.x_diff >= imgs.y_diff)
	{
		// imgs.decision = (2 * imgs.y_diff) - imgs.x_diff;
		draw_acute_slope(imgs, m0, m1);
	}
	else
	{
		imgs.decision = (2 * imgs.x_diff) - imgs.y_diff;
		draw_obtus_slope(imgs, m0, m1);
	}
}






void	draw_line_2(t_img imgs, t_matrix m0, t_matrix m1)
{
	// init_step(&imgs, &m0, &m1);
	imgs.x_diff = abs(m1.x_proj - m0.x_proj);
	imgs.y_diff = abs(m1.y_proj - m0.y_proj);
	if (m1.x_proj < m0.x_proj)
		imgs.x_step = -1;
	if (m1.y_proj < m0.y_proj)
		imgs.y_step = -1;

	//--
	// ft_printf("m0[%d, %d], m1[%d, %d]\n", m0.x_proj, m0.y_proj, m1.x_proj, m1.y_proj);

	while (1)
	{
		if (m0.x_proj >= 0 && m0.x_proj < WIDTH && m0.y_proj > 0 && m0.y_proj < HEIGHT)
			put_pixel(imgs, m0.x_proj, m0.y_proj, m0.color);
		if (m0.x_proj == m1.x_proj && m0.y_proj == m1.y_proj)
			break;
		if (m0.x_proj != m1.x_proj)
			m0.x_proj += imgs.x_step;
		if (m0.y_proj != m1.y_proj)
			m0.y_proj += imgs.y_step;
		// ft_printf("m0[%d, %d]", m0.x_proj, m0.y_proj);
	}
}
