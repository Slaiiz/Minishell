/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 17:21:43 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 18:10:12 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_array.h"

#include "libft_memory.h"

void	**ft_arrnew(size_t len)
{
	void	**new;

	new = malloc(sizeof(*new) * len);
	if (new == NULL)
		return (NULL);
	ft_bzero(new, sizeof(*new) * len);
	return (new);
}
