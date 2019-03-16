#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h> // to delete
# include "libft/libft.h"
#define BUFF_SIZE 300

char 	*ft_rd(char *name);
char	**ft_map(int n);
char	**ft_alg(char *valid, char **map);

#endif