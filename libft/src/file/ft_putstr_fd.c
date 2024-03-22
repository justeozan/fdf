/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:21:43 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/22 15:51:47 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	// ft_printf("Tout est ok3, s = %s\n", s);
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}
