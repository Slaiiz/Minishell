/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 12:50:54 by vchesnea          #+#    #+#             */
/*   Updated: 2017/02/11 17:07:51 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

# undef LIBFT_PRINTF_H
# include "../libft_printf.h"

# define ALT		  0x01
# define ZPAD		  0x02
# define BLANK		  0x04
# define SIGN		  0x08
# define NEGF		  0x10

# define CINT		 0x001
# define CSTR		 0x002
# define CWSTR		 0x004
# define CPTR		 0x008
# define COCT		 0x010
# define CUINT		 0x020
# define CHEXL		 0x040
# define CHEXU		 0x080
# define CCHAR		 0x100
# define CWCHAR		 0x200

# define NUMERIC	0x1000
# define STRING		0x2000
# define POINTER	0x4000

# define APPEND		     1
# define PREPEND	     2

typedef struct	s_buffer
{
	int			fd;
	size_t		len;
	size_t		size;
	char		*data;
	size_t		written;
}				t_buffer;

typedef struct	s_format
{
	char		flags;
	size_t		modif;
	int			prec;
	int			field;
	short		conv;
}				t_format;

void			display_as_dec(t_buffer *buf, t_format *in, size_t arg);

void			display_as_hex(t_buffer *buf, t_format *in, size_t arg);

void			display_as_ptr(t_buffer *buf, t_format *in, size_t arg);

void			display_as_str(t_buffer *buf, t_format *in, size_t arg);

void			parse_extras(t_buffer *in, const char **format);

void			pad_buffer(t_buffer *buf, t_format *in, int fpad, int ppad);

void			write_to_buffer(t_buffer *in, int mode, int len, const char *s);

void			get_flags(t_format *out, const char **s);

void			get_precision(t_format *out, const char **s);

void			get_modifier(t_format *out, const char **s);

void			get_conversion(t_format *out, const char **s);

size_t			sign_extend(t_format *in, size_t arg);

#endif
