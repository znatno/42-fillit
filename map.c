/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 15:32:31 by ibohun            #+#    #+#             */
/*   Updated: 2019/03/24 15:32:33 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_map(int n)
{
	char	**map;
	int		i;

	i = n;
	if (n < 1)
		return (NULL);
	map = (char**)malloc(sizeof(char*) * n);
	while (i--)
	{
		map[i] = (char *)malloc(sizeof(char) * n + 1);
		ft_bzero(map[i], n + 1);
		ft_memset(map[i], '.', (size_t)n);
	}
	return (map);
}

void	ft_newmap(char ***map, t_tetr *lst)
{
	int		i;
	t_tetr	*walk;

	walk = lst;
	i = lst->size;
	while (i--)
		free((*map)[i]);
	free(*map);
	*map = ft_map(++lst->size);
	while (walk)
	{
		walk->x = 0;
		walk->y = 0;
		walk = walk->next;
	}
}
