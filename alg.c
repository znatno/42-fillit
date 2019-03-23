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
		map[i] = (char *) malloc(sizeof(char) * n + 1);
		ft_bzero(map[i], n + 1);
		ft_memset(map[i], '.', (size_t)n);
	}
	return (map);
}

int		ft_check_map(char **map, char *valid, int i, int j, int n)
{
	int	l;

	l = 0;
	while (i < n && *(valid + 1) != '\0')
	{
		j -= l;
		l = 0;
		while (j < n && *valid != '\n' && (map[i][j] == '.' || *valid =='.')
				&& *valid)
		{
			j++;
			valid++;
			l++;
		}
		if (*valid == '\n' && (*(valid + 1) == '#' || *(valid + 1) == '.'))
		{
			i++;
			if (*(valid + 1) == '\n' || *(valid + 1) == '\0')
				continue;
			valid++;
		}
		else if (!(*valid) || (*valid == '\n' && *(valid + 1) == '\n'))
			return (1);
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
		while (*tetr != '\n' && *tetr)
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

void	ft_newmap(char ***map, t_tetr *lst, int *n)
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

char	***ft_tetr(t_tetr *lst, char ***map, int n)
{
	if (ft_check_map(*map, lst->tetr, lst->y, lst->x, n))
	{
		ft_placetetr(map, lst, lst->y, lst->x);
		return (map);
	}
	else
	{
		if (lst->x == n - 1 && lst->y == n - 1)
			return (NULL);
		if (lst->x == n - 1 && lst->y != n - 1)
		{
			lst->x = 0;
			lst->y++;
		}
		else
			lst->x++;
	}
	return (NULL);
}

//int 	ft_newalg(t_tetr *lst, char ***map)
//{
//	if (lst == NULL)
//		return (1);
//	while (1)
//	{
//		if
//	}
//}

char	**ft_alg(t_tetr *lst, char **map, int *n)
{
//	int z;
//
//	z = 0;
//	while (z < *n)
//	{
//		printf("%s\n", map[z]);
//		z++;
//	}
//	printf("\n");
	while (lst)
	{
		if (!ft_tetr(lst, &map, *n))
		{
			if (lst->x == *n - 1 && lst->y == *n - 1 && !lst->prev)
				ft_newmap(&map, lst, n);
			else if (lst->x == *n - 1 && lst->y == *n - 1)
			{
				lst = lst->prev;
				ft_removetetr(&map, lst->let, *n);
				lst->x++;
				if (lst->x == *n && lst->y != *n - 1)
				{
					lst->x = 0;
					lst->y++;
				}
			}
		}
		else
		{
			lst = lst->next;
			if (lst)
			{
				lst->x = 0;
				lst->y = 0;
			}
		}
//		z = 0;
//		while (z < *n)
//		{
//			printf("%s\n", map[z]);
//			z++;
//		}
//		printf("\n");
	}
	return (map);
}

//	int z;
//
//	z = 0;
//	printf("  ДО  \n");
//	while (z < *n)
//	{
//		printf("%s\n", map[z]);
//		z++;
//	}
//	printf("\n");

//		z = 0;
//		printf("  КРОК ПІСЛЯ  \n");
//		while (z < *n)
//		{
//			printf("%s\n", map[z]);
//			z++;
//		}
//		printf("\n");