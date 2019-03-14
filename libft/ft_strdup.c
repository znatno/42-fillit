/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <ibohun@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 21:04:54 by ibohun            #+#    #+#             */
/*   Updated: 2019/02/10 17:23:47 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s)
{
	int		i;
	char	*dup;

	i = ft_strlen(s);
	if (!(dup = malloc(sizeof(*dup) * (i + 1))))
		return (NULL);
	ft_strcpy(dup, s);
	return (dup);
}
