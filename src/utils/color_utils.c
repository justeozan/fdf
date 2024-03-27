/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:44:07 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/27 09:48:27 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_argb	create_argb(int color)
{
	t_argb	argb;
	int		mask;

	mask = 0xFF;
	argb.a = (unsigned char)(color >> 24) & mask;
	argb.r = (unsigned char)(color >> 16) & mask;
	argb.g = (unsigned char)(color >> 8) & mask;
	argb.b = (unsigned char)color & mask;
	return (argb);
}

int	create_color_gradient(float delta, t_argb color1, t_argb color2)
{
	t_argb	new_c;
	int		color_int;

	new_c.a = (1 - delta) * color1.a + delta * color2.a;
	new_c.r = (1 - delta) * color1.r + delta * color2.r;
	new_c.g = (1 - delta) * color1.g + delta * color2.g;
	new_c.b = (1 - delta) * color1.b + delta * color2.b;
	color_int = (new_c.a << 24) + (new_c.r << 16) + (new_c.g << 8) + new_c.b;
	return (color_int);
}

int	process_color(int curr_steps, int tot_steps, int color_ini, int color_end)
{
	float	delta;
	int		c_processed;

	delta = (float) curr_steps / tot_steps;
	c_processed = create_color_gradient(delta,
			create_argb(color_ini), create_argb(color_end));
	return (c_processed);
}
