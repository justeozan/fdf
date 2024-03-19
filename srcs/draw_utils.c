#include "../include/fdf.h"

void	isometric(t_fdf *dot, double angle)
{
	dot->x = (dot->x - dot->y) * cos(angle);
	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}

void	zoom(t_fdf *a, t_fdf *b, t_fdf *data)
{
	a->x *= data->scale;
	a->y *= data->scale;
	b->x *= data->scale;
	b->y *= data->scale;
	a->z *= data->z_scale;
	b->z *= data->z_scale;
}

void	set_param(t_fdf *a, t_fdf *b, t_fdf *data)
{
	zoom(a, b, data);
	if (data->is_isometric)
	{
		isometric(a, data->angle);
		isometric(b, data->angle);
	}
	a->x += data->shift_x;
	a->y += data->shift_y;
	b->x += data->shift_x;
	b->y += data->shift_y;
}

float	find_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	find_absolute(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}