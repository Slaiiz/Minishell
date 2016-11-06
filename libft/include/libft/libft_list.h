/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 12:50:21 by vchesnea          #+#    #+#             */
/*   Updated: 11/6/2016, 4:39:24 PM by vchesnea       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H
# define LIBFT_LIST_H

#include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

t_list				*ft_lstdup(t_list *lst);

void				ft_lstiter(t_list *lst, void (*f)(t_list *));

size_t				ft_lstlen(t_list *lst);

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *));

t_list				*ft_lstnew(const void *content, size_t content_size);

#endif
