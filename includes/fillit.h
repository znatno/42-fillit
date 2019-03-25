/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 15:58:06 by ibohun            #+#    #+#             */
/*   Updated: 2019/03/24 20:59:30 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "../libft/libft.h"
# define BUFF_SIZE 2019

typedef struct		s_tetr
{
	int				x;
	int				y;
	int				size;
	int				i;
	char			let;
	char			*t;
	struct s_tetr	*prev;
	struct s_tetr	*next;
}					t_tetr;

char				**ft_map(int n);
void				ft_newmap(char ***map, t_tetr *lst);
char				**ft_alg(t_tetr *lst, char **map);
t_tetr				*ft_newlst(char *valid);
t_tetr				*ft_movelst(t_tetr *lst);
void				ft_del(char *map, int len, int str);
void				ft_trim(char *map);
char				*ft_vl(int fd);
#endif
