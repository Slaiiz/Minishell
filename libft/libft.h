/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:54:22 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/31 15:56:28 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_buff
{
	void			*data;
	size_t			size;
	size_t			len;
}					t_buff;

int					ft_abs(int n);
void				ft_arraydel(void ***array);
int					ft_arraylen(void **array);
int					ft_atoi(char const *str);
int					ft_bufadd(t_buff *buf, const void *data, ssize_t size);
void				ft_bufdel(t_buff **buf);
size_t				ft_bufsub(t_buff *buf, void *out, ssize_t size);
t_buff				*ft_bufnew(size_t size);
void				ft_bzero(void *s, size_t len);
char				*ft_chrrep(char *str, char c, char **rep);
int					ft_expect(char const **s, char const *format, ...);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isblank(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
char				*ft_itoa64(long n);
char				*ft_itoa_base(int n, int base);
char				*ft_itoa_base64(long n, int base);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
t_list				*ft_lstdup(t_list *lst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
size_t				ft_lstlen(t_list *lst);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
int					ft_max(int a, int b);
void				*ft_memalloc(size_t size);
void				*ft_memchr(void const *s, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
void				*ft_memcpy(void *dst, void const *src, size_t n);
void				*ft_memccpy(void *dst, void const *src, int c, size_t n);
void				ft_memdel(void **ap);
void				*ft_memdup(const void *addr, size_t n);
void				*ft_memmove(void *dst, void const *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					ft_min(int a, int b);
size_t				ft_nbrlen(size_t n, int base);
int					ft_parseint(char const *str, int *out);
int					ft_printf(char const *format, ...);
void				ft_printmem(void const *addr, size_t size);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_base(int n, int base);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_rot13(char *s);
int					ft_seekstr(char const **a, char const *b);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strcmp(char const *s1, char const *s2);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strcat(char *s1, char const *s2);
char				*ft_strchr(char const *s, int c);
char				*ft_strcpy(char *dst, char const *src);
char				*ft_strdup(char const *s1);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, char const *src, size_t n);
size_t				ft_strlen(char const *s);
char				*ft_strlowcase(char *s);
char				*ft_strncat(char *s1, char const *s2, size_t n);
char				*ft_strncpy(char *dst, char const *src, size_t n);
char				*ft_strndup(char const *s1, size_t n);
char				*ft_strupcase(char *s);
char				*ft_strrev(char *str);
char				*ft_strrchr(char const *s, int c);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnew(size_t size);
char				*ft_strnstr(char const *s1, char const *s2, size_t n);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_uitoa(unsigned int n);
char				*ft_uitoa64(unsigned long n);
char				*ft_uitoa_base(unsigned int n, int base);
char				*ft_uitoa_base64(unsigned long n, int base);

#endif
