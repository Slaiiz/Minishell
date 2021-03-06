/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:46:54 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 14:59:30 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_list.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list	*out;
	t_list	*tmp;

	if ((out = f(lst)) == NULL)
		return (NULL);
	tmp = out;
	lst = lst->next;
	while (lst != NULL)
	{
		if ((tmp->next = f(lst)) == NULL)
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (out);
}
