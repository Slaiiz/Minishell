/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_qtree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 12:51:28 by vchesnea          #+#    #+#             */
/*   Updated: 2017/02/11 17:50:20 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_QTREE_H
# define LIBFT_QTREE_H

# include <stdlib.h>

typedef struct		s_qtree
{
	void			*data;
	struct s_qtree	*nw;
	struct s_qtree	*ne;
	struct s_qtree	*se;
	struct s_qtree	*sw;
	struct s_qtree	*parent;
}					t_qtree;

t_qtree				*ft_qtreenew(int x, int y, void *data);

#endif
