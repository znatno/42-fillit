/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:02:46 by vslutiak          #+#    #+#             */
/*   Updated: 2018/11/12 18:13:36 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_len(char *map)
{
	char	*buffer;

	buffer = map;
	while (*map && *map != '\n')
		++map;
	return (map - buffer);
}

int		ft_empty(char *map, int len, int str)
{
	while (*map && str--)
	{
		if (*map == '\n')
			return (1);
		if (*map == '#')
			return (0);
		map += len + 1;
	}
	return (1);
}

int		count_line(char *map)
{
	int		i;

	i = 0;
	while (*map)
	{
		if (*map == '\n')
			i++;
		if (*map == '\n' && *(map + 1) == '\n')
			return (i);
		map++;
	}
	return (i);
}

void	del_emp(char *map)
{
	while (*map)
		if ((ft_strncmp(map, "....\n", 5)) == 0)
			ft_memmove(map, map + 5, ft_strlen(map + 4));
		else
			++map;
}

void	ft_trim(char *map)
{
	int	len;
	int	str;
	int	col;

	del_emp(map);
	while (*map)
	{
		len = ft_len(map);
		str = count_line(map);
		col = len;
		while (col--)
		{
			if (ft_empty(map, len, str))
			{
				ft_del(map, len, str);
				--len;
			}
			if (ft_empty(map + (len - 1), len, str))
			{
				ft_del(map + (len - 1), len, str);
				--len;
			}
		}
		map += ((len + 1) * str) + 1;
	}
}
