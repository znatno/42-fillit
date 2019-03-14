#include "fillit.h"

char 	ft_rd(char *name)
{
	char	*file;

	file = malloc(sizeof(char*));
	if ((fd = open(name, O_RDONLY) > 0)
	{
		while (read(1, file, 1))
		{

		}
		return (file);
	}
	return  (NULL);
}