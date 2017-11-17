/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:43:34 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 14:59:18 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_list.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *))
{
	while (lst != NULL)
	{
		f(lst);
		lst = lst->next;
	}
}
