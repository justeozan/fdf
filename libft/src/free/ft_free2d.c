/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:25:31 by ozasahin          #+#    #+#             */
/*   Updated: 2024/03/27 16:24:11 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_free2d(char **strs)
{
	unsigned int	i;

	i = 0;
	if (strs == NULL || *strs == NULL)
		return (-1);
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (0);
}

void	ft_freen2d(char **strs, size_t nb_subs)
{
	size_t	i;

	i = 0;
	if (strs == NULL || *strs == NULL)
		return ;
	while (i < nb_subs && strs[i])
		free(strs[i++]);
	free(strs);
	strs = NULL;
}
