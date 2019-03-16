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
	char	*valid;
	t_tetr	*lst;
	int n;

	n = 3;
	valid = ft_rd(av[1]);
	map = ft_map(n);
	lst = ft_newlst(valid);
//	map = ft_alg(valid, map, n);
//	ft_print_map(map);
	while (lst)
	{
		printf("%s\n", lst->tetr);
		lst = lst->next;
	}
	printf("great!\n");
	return (0);
}
