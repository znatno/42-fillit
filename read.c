#include "fillit.h"

static t_tetr	*ft_addtetr(char **valid, t_tetr *curr)
{
	curr->x = 0;
	curr->y = 0;
	curr->tetr = *valid;
	curr->prev = NULL;
	curr->next = NULL;
	while (!(**valid == '\n' && *(*valid + 1) == '\n') && **valid)
		(*valid)++;
	if (**valid == '\n' && *(*valid + 1) == '\n' && **valid)
	{
		if (*(valid + 1) == '\0')
			(*valid)++;
		else
			(*valid) += 2;
	}
	return (curr);
}

t_tetr			*ft_newlst(char *valid)
{
	t_tetr	*head;
	t_tetr	*prev;
	t_tetr	*curr;

	head = NULL;
	prev = NULL;
	while (*valid)
	{
		if (!(curr = (t_tetr*)malloc(sizeof(t_tetr))))
			return (NULL);
		curr = ft_addtetr(&valid, curr);
		if (!head)
			head = curr;
		else
		{
			prev->next = curr;
			curr->prev = prev;
		}
		prev = curr;
	}
	return (head);
}

char 			*ft_rd(char *name)
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