/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_special.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 12:51:45 by vchesnea          #+#    #+#             */
/*   Updated: 11/6/2016, 4:39:37 PM by vchesnea       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_SPECIAL_H
# define LIBFT_SPECIAL_H

#include <stdlib.h>

char	*ft_chrrep(char *str, char c, char **rep);

int		ft_expect(const char **s, const char *format, ...);

void	ft_printmem(const void *addr, size_t size);

char	*ft_rot13(char *s);

int		ft_seekstr(const char **a, const char *b);

#endif