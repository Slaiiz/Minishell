/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_io.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 12:50:10 by vchesnea          #+#    #+#             */
/*   Updated: 2017/02/11 17:13:07 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_IO_H
# define LIBFT_IO_H

void	ft_putchar_fd(char c, int fd);

void	ft_putchar(char c);

void	ft_putendl_fd(const char *s, int fd);

void	ft_putendl(const char *s);

void	ft_putnbr_base(int n, int base);

void	ft_putnbr_fd(int n, int fd);

void	ft_putnbr(int n);

void	ft_putstr_fd(const char *s, int fd);

void	ft_putstr(const char *s);

#endif
