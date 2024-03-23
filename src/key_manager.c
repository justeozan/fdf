/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:07:58 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/23 11:21:21 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int is_key(int key)
{
    return(key == PLUS || key == MINUS);
}

void    do_key(int key, t_matrix **matrix)
{
    if (key == PLUS)
	    FDF.scale += 3;
	if (key == MINUS)
		FDF.scale -= 3;
}

int    manage_key(int key, t_matrix **matrix)
{
    ft_printf("key = %d\n", key);
    if (is_key(key))
    {
        do_key(key, matrix);
        // print_menu(FDF);
        // frame() ?
    }
    // if (key == ONE)
    //     new_window();
    if (key == SPACE)
        close_normal(matrix);
    return (0);
}