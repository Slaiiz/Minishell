/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_integer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 12:49:19 by vchesnea          #+#    #+#             */
/*   Updated: 11/6/2016, 4:39:19 PM by vchesnea       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_INTEGER_H
# define LIBFT_INTEGER_H

#include <stdlib.h>

int	ft_abs(int n);

int	ft_atoi(const char *str);

int	ft_max(int a, int b);

int	ft_min(int a, int b);

int	ft_nbrlen(size_t n, int base);

int	ft_parseint(const char *str, int *out);

#endif
