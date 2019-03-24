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

#include <stdio.h>
#include "fillit.h"

/*
** зчитувач з валідатора & обрізаних фігур до її меж
** алгоритм знаходження найменшої фігури вліво вгору
** знаходимо крайній правий кут нанесеної фігури і переміщуємось далі
** провіряємо на карті чи можна
** видрук
*/

int	main(int ac, char **av)
{
	char	**map;
	char	*valid;
	t_tetr	*lst;
	int		i;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit valid_map_file");
		return (-1);
	}
	valid = THERE_ARE_NEED_TO_BE_VALIDATION_AND_TRIM;
	lst = ft_newlst(valid);
	map = ft_map(lst->size);
	map = ft_alg(lst, map);
	i = -1;
	while (++i < lst->size)
		ft_putendl(map[i]);
	return (0);
}
