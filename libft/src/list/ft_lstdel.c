/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:32:10 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 14:57:55 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_list.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*curr;
	t_list	*next;

	curr = *alst;
	while (curr != NULL)
	{
		next = curr->next;
		if (del != NULL)
			del(curr->content, curr->content_size);
		free(curr);
		curr = next;
	}
	*alst = NULL;
}
