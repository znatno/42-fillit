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

	valid = ft_rd(av[1]);
	map = ft_map(2);
	map = ft_alg(valid, map);
//	ft_print_map(map);
	return (0);
}
