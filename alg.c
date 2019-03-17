/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 18:27:32 by ibohun            #+#    #+#             */
/*   Updated: 2019/03/17 18:27:35 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_map(int n)
{
	char	**map;
	int 	i;

	i = n;
	if (n < 1)
		return (NULL);
	map = (char**)malloc(sizeof(char*) * n);
	while (i--)
	{
		map[i] = (char *) malloc(sizeof(char) * n);
		ft_memset(map[i], '.', (size_t)n);
	}
	return (map);
}

int		ft_check_map(char **map, char *valid, int i, int j, int n)
{
	int	l;

	l = 0;
	while (i < n && *(valid + 1) != '\n' && *(valid + 1) != '\0')
	{
		j -= l;
		l = 0;
		while (j < n && *valid != '\n' && map[i][j] != '#')
		{
			j++;
			valid++;
			l++;
		}
		if (*valid == '\n')
		{
			i++;
			if (*(valid + 1) != '\n')
				valid++;
		}
		else
			return (0);
	}
	if (*valid == '\n' && (*(valid + 1) == '\n' || *(valid + 1) == '\0'))
		return (1);
	else
		return (0);
}

void	ft_placetetr(char ***map, t_tetr *lst, int i, int j)
{
	char 	*tetr;

	lst->tmp = 0;
	tetr = lst->tetr;
	lst->x = j;
	lst->y = i;
	while (*tetr)
	{

		while (*tetr != '\n')
		{
			if (*tetr == '#')
				(*map)[i][j] = lst->let;
			j++;
			tetr++;
			lst->tmp++;
		}
		j -= lst->tmp;
		lst->tmp = 0;
		i++;
		if (*tetr == '\n' && (*(tetr + 1) == '\n' || *(tetr + 1) == '\0'))
			break;
		tetr++;
	}
}

void	ft_removetetr(char ***map, t_tetr *lst)
{
	char 	*tetr;
	int 	i;
	int 	j;

	i = lst->y;
	j = lst->x;
	lst->tmp = 0;
	tetr = lst->tetr;
	while (*tetr)
	{
		while (*tetr != '\n')
		{
			if (*tetr == '#')
				(*map)[i][j] = '.';
			j++;
			tetr++;
			lst->tmp++;
		}
		j -= lst->tmp;
		lst->tmp = 0;
		if (*tetr == '\n' && (*(tetr + 1) == '\n' || *(tetr + 1) == '\0'))
			break;
		i++;
		tetr++;
	}
}

char	***ft_tetr(t_tetr *lst, char ***map, int n)
{
	if (ft_check_map(*map, lst->tetr, lst->y, lst->x, n))
	{
		ft_placetetr(map, lst, lst->y, lst->x);
		return (map);
	}
	return (NULL);
}

void	ft_newlife(char ***map, t_tetr *lst, int *n)
{
	int		i;
	t_tetr	*walk;

	walk = lst;
	i = *n;
	while (i--)
		free((*map)[i]);
	*map = ft_map(++(*n));
	while (walk)
	{
		walk->x = 0;
		walk->y = 0;
		walk = walk->next;
	}
}

char	**ft_alg(t_tetr *lst, char **map, int *n)
{
	int z;

	z = 0;
	printf("  ДО  \n");
	while (z < *n)
	{
		printf("%s\n", map[z]);
		z++;
	}
	printf("\n");
	while (lst)
	{
		if (!ft_tetr(lst, &map, *n))
		{
			if (lst->prev)
			{
				lst = lst->prev;
				ft_removetetr(&map, lst);
				lst->x++;
				if (lst->x == *n)
				{
					lst->x = 0;
					lst->y++;
					if (lst->y == *n)
						continue;
				}
			}
			else if (lst->y == *n)
			{
				ft_newlife(&map, lst, n);
			}
		}
		else
		{
			lst = lst->next;
			lst->x = 0;
			lst->y = 0;
		}
		z = 0;
		printf("  ПІСЛЯ  \n");
		while (z < *n)
		{
			printf("%s\n", map[z]);
			z++;
		}
		printf("\n");
	}
	return (map);
}
