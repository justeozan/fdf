/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:22:14 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/22 16:07:16 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	exit_err(char *err_txt)
{

	ft_putstr_fd(err_txt, 2);
	ft_printf("Tout est ok5\n");
	exit(EXIT_FAILURE);
}

// int main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		ft_print_err(av[1]);
// 	}
// 	return (0);
// }
