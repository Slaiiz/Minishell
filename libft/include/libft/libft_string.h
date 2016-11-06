/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 12:51:58 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/06 18:18:30 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRING_H
# define LIBFT_STRING_H

#include <stdlib.h>

int		ft_isalnum(int c);

int		ft_isalpha(int c);

int		ft_isascii(int c);

int		ft_isblank(int c);

int		ft_isdigit(int c);

int		ft_isprint(int c);

char	*ft_itoa_base(int n, int base);

char	*ft_itoa_base64(long n, int base);

char	*ft_itoa(int n);

char	*ft_itoa64(long n);

char	*ft_strcat(char *s1, const char *s2);

char	*ft_strchr(const char *s, int c);

void	ft_strclr(char *s);

int		ft_strcmp(const char *s1, const char *s2);

int		ft_strcmpcase(const char *s1, const char *s2);

char	*ft_strcpy(char *dst, const char *src);

void	ft_strdel(char **as);

char	*ft_strdup(const char *s1);

int		ft_strequ(const char *s1, const char *s2);

void	ft_striter(char *s, void (*f)(char *));

void	ft_striteri(char *s, void (*f)(unsigned int, char *));

char	*ft_strjoin(const char *s1, const char *s2);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

size_t	ft_strlen(const char *s);

char	*ft_strlowcase(char *s);

char	*ft_strmap(const char *s, char (*f)(char));

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

char	*ft_strncat(char *s1, const char *s2, size_t n);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strncpy(char *dst, const char *src, size_t n);

char	*ft_strndup(const char *s1, size_t n);

int		ft_strnequ(const char *s1, const char *s2, size_t n);

char	*ft_strnew(size_t size);

char	*ft_strnstr(const char *s1, const char *s2, size_t n);

char	*ft_strrchr(const char *s, int c);

char	*ft_strrev(char *str);

char	**ft_strsplit(const char *s, char c);

char	*ft_strstr(const char *s1, const char *s2);

char	*ft_strsub(const char *s, unsigned int start, size_t len);

char	*ft_strtrim(const char *s);

char	*ft_strupcase(char *s);

int		ft_tolower(int c);

int		ft_toupper(int c);

char	*ft_uitoa_base(unsigned int n, int base);

char	*ft_uitoa_base64(unsigned long n, int base);

char	*ft_uitoa(unsigned int n);

char	*ft_uitoa64(unsigned long n);

#endif
