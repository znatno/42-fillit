#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h> // to delete
# include "libft/libft.h"
#define BUFF_SIZE 300

typedef struct		s_tetr
{
	int				x;
	int				y;
	char			*tetr;
	struct s_tetr	*prev;
	struct s_tetr	*next;
}					t_tetr;

char 				*ft_rd(char *name);
char				**ft_map(int n);
char				**ft_alg(char *valid, char **map, int n);
t_tetr				*ft_newlst(char *valid);
#endif