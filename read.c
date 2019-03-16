
#include "fillit.h"

char 	*ft_rd(char *name)
{
	char	*file;
	char 	buf[300];
	int 	fd;

	if ((fd = open(name, O_RDONLY)) == -1)
		return (NULL);
	else
		file = ft_strnew(1);
	while ((read(fd, buf, 300) > 0))
	{
		file = ft_strjoin(file, buf);
		ft_bzero(buf, 300);
	}
	close(fd);
	return (file);
}