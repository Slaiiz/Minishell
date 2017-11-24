/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:35:35 by vchesnea          #+#    #+#             */
/*   Updated: 2017/11/24 18:38:11 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_list.h"

void		ft_lstfree(t_list **alst)
{
	t_list	*curr;
	t_list	*next;

	curr = *alst;
	while (curr != NULL)
	{
		next = curr->next;
		if (curr->content != NULL)
			free(curr->content);
		free(curr);
		curr = next;
	}
	*alst = NULL;
}
