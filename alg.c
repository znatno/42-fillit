/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 18:27:32 by ibohun            #+#    #+#             */
/*   Updated: 2019/03/24 20:57:50 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_map(char **map, t_tetr lst)
{
	lst.i = 0;
	while (lst.y < lst.size)
	{
		lst.x -= lst.i;
		lst.i = 0;
		while (lst.x < lst.size && *lst.t != '\n'
				&& (map[lst.y][lst.x] == '.' || *lst.t == '.') && *lst.t)
			if (++lst.x && ++lst.t)
				++lst.i;
		if (*lst.t == '\n' && (*(lst.t + 1) == '#' || *(lst.t + 1) == '.'))
		{
			lst.y++;
			if (*(lst.t + 1) == '\n' || *(lst.t + 1) == '\0')
				continue;
			lst.t++;
		}
		else if (!(*lst.t) || (*lst.t == '\n' && *(lst.t + 1) == '\n'))
			return (1);
		else
			return (0);
	}
	if ((*lst.t == '\n') && (*(lst.t + 1) == '\n' || *(lst.t + 1) == '\0'))
		return (1);
	else
		return (0);
}

void	ft_placetetr(char ***map, t_tetr *lst, int i, int j)
{
	char *tetr;

	lst->i = 0;
	tetr = lst->t;
	lst->x = j;
	lst->y = i;
	while (*tetr)
	{
		while (*tetr != '\n' && *tetr)
		{
			if (*tetr == '#')
				(*map)[i][j] = lst->let;
			j++;
			tetr++;
			lst->i++;
		}
		j -= lst->i;
		lst->i = 0;
		i++;
		if (*tetr == '\n' && (*(tetr + 1) == '\n' || *(tetr + 1) == '\0'))
			break ;
		tetr++;
	}
}

void	ft_removetetr(char ***map, char c, int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < n)
	{
		while (j < n)
		{
			if ((*map)[i][j] == c)
				(*map)[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}

char	***ft_tetr(t_tetr *lst, char ***map)
{
	if (ft_check_map(*map, *lst))
	{
		ft_placetetr(map, lst, lst->y, lst->x);
		return (map);
	}
	else
	{
		if (lst->x == lst->size && lst->y == lst->size - 1)
			return (NULL);
		if (lst->x == lst->size - 1 && lst->y != lst->size - 1)
		{
			lst->x = 0;
			lst->y++;
		}
		else
			lst->x++;
	}
	return (NULL);
}

char	**ft_alg(t_tetr *lst, char **map)
{
	while (lst)
	{
		if (!ft_tetr(lst, &map))
		{
			if (lst->x == lst->size - 1 && lst->y == lst->size - 1
				&& !lst->prev)
				ft_newmap(&map, lst);
			else if (lst->x == lst->size - 1 && lst->y == lst->size - 1)
			{
				lst = lst->prev;
				ft_removetetr(&map, lst->let, lst->size);
				lst->x++;
				if (lst->x == lst->size && lst->y != lst->size - 1)
				{
					lst->x = 0;
					lst->y++;
				}
			}
		}
		else
			lst = ft_movelst(lst);
	}
	return (map);
}
