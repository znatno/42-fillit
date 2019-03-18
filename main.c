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
 * зчитувач
 * валідатор & обрізати фігуру до її меж
 * алгоритм знаходження найменшої фігури вліво вгору
 * знаходимо крайній правий кут нанесеної фігури і переміщуємось далі
 * провіряємо на карті чи можна
 * видрук
*/

int     main(int ac, char **av)
{
	char	**map;
	char 	**print_map;
	char	*valid;
	t_tetr	*lst;
	int n;
	int i = 0;
	int numb_of_tetr = 4;

	n = 2;
	valid = ft_rd(av[1]);
	map = ft_map(n);
	lst = ft_newlst(valid);
	map = ft_alg(lst, map, &n);
	printf("\n\nRESULT:\n");
	while (i < n)
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("\n\nn: %d\n", n);
	return (0);
}
