/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <ibohun@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:54:34 by ibohun            #+#    #+#             */
/*   Updated: 2019/03/13 14:21:20 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*ft_new_list(const int fd)
{
	t_gnl	*new;

	if (!(new = (t_gnl*)malloc(sizeof(*new))))
		return (NULL);
	new->fd = fd;
	new->tmp = ft_strnew(0);
	new->text = NULL;
	new->next = NULL;
	return (new);
}

static t_gnl	*ft_fd_check(t_gnl *saved, int fd)
{
	t_gnl	*clist;
	t_gnl	*new;
	t_gnl	*add;

	new = NULL;
	clist = saved;
	while (clist)
	{
		if (clist->fd == fd)
			return (clist);
		if (!(clist->next))
		{
			new = ft_new_list(fd);
			add = clist;
			while (add->next)
				add = add->next;
			add->next = new;
			return (new);
		}
		clist = clist->next;
	}
	return (NULL);
}

static int		ft_rtrn_check(char *str, char **line)
{
	char	*l_end;

	if (!(str))
		return (0);
	l_end = ft_strchr(str, '\n');
	if (l_end != NULL)
	{
		*l_end = '\0';
		*line = ft_strdup(str);
		ft_strncpy(str, &l_end[1], ft_strlen(&l_end[1]) + 1);
		return (GOING_MORE);
	}
	else if (ft_strlen(str) > 0)
	{
		*line = ft_strdup(str);
		*str = '\0';
		return (GOING_MORE);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*saved;
	t_gnl			*now;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (ERROR);
	if (!(saved))
		saved = ft_new_list(fd);
	now = ft_fd_check(saved, fd);
	while (!(ft_strchr(now->tmp, '\n')))
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (ERROR);
		if (ret == 0)
			return (ft_rtrn_check(now->tmp, line));
		buf[ret] = '\0';
		now->text = ft_strjoin(now->tmp, buf);
		free(now->tmp);
		now->tmp = now->text;
	}
	return (ft_rtrn_check(now->tmp, line));
}
