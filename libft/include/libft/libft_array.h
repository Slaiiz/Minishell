/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_array.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 17:43:49 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/06 18:18:20 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ARRAY_H
# define LIBFT_ARRAY_H

#include <stdlib.h>

void	ft_arrdel(void ***array, size_t len, void (*f)(void**));

void	ft_arriter(void **array, size_t len, void (*f)(void**));

void	**ft_arrnew(size_t len);

#endif
