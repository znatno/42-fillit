/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:02:46 by vslutiak          #+#    #+#             */
/*   Updated: 2019/03/25 12:24:21 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_new_line(char *map, int l)
{
	int	i;
	int	b;

	i = 4;
	b = 0;
	while (i < l)
	{
		while (++b <= 3)
			if (map[i] == '\n')
				i += 5;
			else
				return (0);
		b = 0;
		if (map[l - 1] == '\n' && map[l - 2] == '\n' && map[l - 3] == '\n')
			return (0);
		if (map[i] == '\n' && map[i + 1] == '\n' && map[i + 2] == '\0')
			return (0);
		if (map[i] == '\n' && map[i + 1] == '\n')
			i += 6;
		else if (map[i] == '\n' && map[i + 1] == '\0')
			break ;
		else
			return (0);
	}
	return (1);
}

int		ft_line(char *map)
{
	int col;
	int i;

	i = 0;
	col = 0;
	while (map[i])
	{
		if (map[i] != '\n')
			col++;
		if (map[i] != '\n' && map[i] != '.' && map[i] != '#')
			return (0);
		i++;
	}
	if (col % 16 == 0)
		return (1);
	return (0);
}

int		ft_valid(int len, char *map)
{
	int	i;
	int	b;
	int count;

	i = 0;
	b = 1;
	count = 0;
	while (i < len && b <= 20)
	{
		(map[i] == '#' && b > 1 && map[i - 1] == '#') ? ++count : count;
		(map[i] == '#' && b < 19 && map[i + 1] == '#') ? ++count : count;
		(map[i] == '#' && b > 5 && map[i - 5] == '#') ? ++count : count;
		(map[i] == '#' && b < 15 && map[i + 5] == '#') ? ++count : count;
		if (b == 20)
		{
			if (count != 6 && count != 8)
				return (0);
			b = 0;
			count = 0;
			++i;
		}
		i++;
		b++;
	}
	return (1);
}

int		ft_count(char *map, int len)
{
	int i;
	int b;
	int count;

	i = 0;
	b = 1;
	count = 0;
	if (!map[i])
		return (0);
	while (i < len)
	{
		if (map[i] == '#')
			count++;
		if (b == 20)
		{
			if (count != 4)
				return (0);
			b = 0;
			count = 0;
			i++;
		}
		i++;
		b++;
	}
	return (1);
}

char	*ft_vl(int fd)
{
	int		len;
	char	buffer[BUFF_SIZE + 1];
	char	*map;

	len = read(fd, buffer, BUFF_SIZE);
	buffer[len] = '\0';
	map = ft_strsub(buffer, 0, len);
	if (ft_valid(len, map) != 1 || ft_line(map) != 1
		|| ft_new_line(map, len) != 1 || ft_count(map, len) != 1)
	{
		free(map);
		write(1, "error\n", 6);
		return (0);
	}
	ft_trim(map);
	map[ft_strlen(map) - 1] = '\0';
	return (map);
}
