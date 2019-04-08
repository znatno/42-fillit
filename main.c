/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 14:17:21 by ibohun            #+#    #+#             */
/*   Updated: 2019/03/17 14:17:22 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	char	**map;
	char	*valid;
	t_tetr	*lst;
	int		i;
	int		fd;

	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
	{
		ft_putendl("usage: ./fillit valid_map_file");
		return (-1);
	}
	if (!(valid = ft_vl(fd)))
		return (0);
	lst = ft_newlst(valid);
	map = ft_map(lst->size);
	map = ft_alg(lst, map);
	i = -1;
	while (++i < lst->size)
		ft_putendl(map[i]);
	close(fd);
	return (0);
}
