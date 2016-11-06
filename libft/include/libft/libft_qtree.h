/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_qtree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 12:51:28 by vchesnea          #+#    #+#             */
/*   Updated: 11/6/2016, 4:39:35 PM by vchesnea       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_QTREE_H
# define LIBFT_QTREE_H

#include <stdlib.h>

typedef enum		e_qtype
{
	TYPE_LEAF,
	TYPE_TREE
}					t_qtype;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_qtree
{
	struct s_qtree	*ne;
	struct s_qtree	*se;
	struct s_qtree	*sw;
	struct s_qtree	*nw;
	struct s_point	pos;
	struct s_point	len;
	enum e_qtype	type;
	void			*data;
}					t_qtree;

void				ft_qtreedel(t_qtree **qtree, void(*f)(void *));

void				ft_qtreeget(t_qtree *qtree, int x, int y);

void				ft_qtreeiter(t_qtree *qtree, void (*f)(t_qtree *));

t_qtree				*ft_qtreenew(int sx, int sy, void *data);

int					ft_qtreeset(t_qtree *qtree, int x, int y, void *data);

#endif
