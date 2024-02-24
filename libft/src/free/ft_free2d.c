/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:25:31 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/23 11:51:09 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_free2d(char ***strs)
{
	unsigned int	i;

	i = 0;
	if (strs == NULL || *strs == NULL)
		return ;
	while ((*strs)[i])
	{
		free((*strs)[i]);
		(*strs)[i] = NULL;
	}
	free(*strs);
	(*strs) = NULL;
}
