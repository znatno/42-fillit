#include <stdio.h>
#include "fillit.h"

int main(int ac, char **av)
{
//    int fd;
//    int ret;
//    char buf[300];

    printf("Hello, World!\n");
    printf("%s\n", av[1]);

//    fd = open(av[1], O_RDONLY);
//    ret = read(fd, buf, 300);
//    ret++;
    printf("%s", ft_rd(av[1]));
    /*
     * зчитувач
     * валідатор & обрізати фігуру до її меж
     * алгоритм знаходження найменшої фігури вліво вгору
     * знаходимо крайній правий кут нанесеної фігури і переміщуємось далі
     * провіряємо на карті чи можна
     * видрук
    */
    return (0);
}