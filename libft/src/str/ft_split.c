/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:51:39 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/25 16:43:45 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	free_subs(char **strs, size_t nb_subs)
{
	size_t	i;

	i = 0;
	while (i < nb_subs)
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	strs = NULL;
}

static int	count_subchain(char *s, char c)
{
	unsigned int	count;
	size_t			i;
	int				is_separator;

	is_separator = 1;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && is_separator)
			count++;
		is_separator = (c == s[i]);
		i++;
	}
	return (count);
}

static char	*create_subchain(char *s, char c)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = 0;
	str = NULL;
	while (s[len] && s[len] != c)
		len++;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (free(str), NULL);
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	create_strs(char const *s, char **strs, char c)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			strs[j] = create_subchain((char *)&s[i], c);
			if (strs[j] == NULL)
			{
				free_subs(strs, j);
				return (0);
			}
			j++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	strs[j] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	size_t	len_subchain;

	if (s == NULL)
		return (NULL);
	len_subchain = count_subchain((char *)s, c);
	strs = (char **)malloc((len_subchain + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	if (!create_strs(s, strs, c))
	{
		free_subs(strs, len_subchain);
		free(strs);
		strs = NULL;
	}
	return (strs);
}

// int	main(int ac, char **av)
// {
// 	char **split;

// 	if (ac == 3)
// 	{
// 		split = ft_split(av[1], av[2][0]);
// 	}
// 	ft_free2d(&split);
// 	return (0);
// }
