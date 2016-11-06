/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:18:59 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:09:46 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_special.h"

#include "libft_integer.h"
#include "libft_string.h"

static int	read_number(const char **s, const char **format, va_list argp)
{
	size_t			n;
	void			*dst;
	const char		*tmp;

	tmp = *s;
	while (ft_isdigit(*tmp))
		++tmp;
	if ((tmp - *s) == 0)
		return (1);
	dst = va_arg(argp, size_t*);
	if (dst != NULL)
	{
		n = ft_atoi(*s);
		if (**format == 'b')
			*(unsigned char*)dst = n;
		else if (**format == 'h')
			*(unsigned short*)dst = n;
		else if (**format == 'w')
			*(unsigned int*)dst = n;
		else if (**format == 'g')
			*(unsigned long*)dst = n;
	}
	*s = tmp;
	++*format;
	return (0);
}

static int	read_identifier(const char **s, va_list argp)
{
	const char	*tmp;
	const char	**dst;

	tmp = *s;
	if (!ft_isalpha(*tmp++))
		return (1);
	while (ft_isalnum(*tmp))
		++tmp;
	dst = va_arg(argp, const char**);
	if (dst != NULL)
		if ((*(char**)dst = ft_strsub(*s, 0, tmp - *s)) == NULL)
			return (-1);
	*s = tmp;
	return (0);
}

static int	read_wildcard(const char **s, const char **format, va_list argp)
{
	size_t		i;
	const char	*tmp;
	const char	**dst;

	i = 0;
	tmp = *s;
	while (*tmp != '\0')
	{
		if (*tmp != **format && ++tmp)
			continue ;
		while (tmp[i] && tmp[i] == (*format)[i])
			++i;
		if ((*format)[i] == '\0' || (*format)[i] == '$')
			break ;
		return (-1);
	}
	*format = &(*format)[i];
	dst = va_arg(argp, const char **);
	if (dst != NULL)
		if ((*(char**)dst = ft_strsub(*s, 0, tmp - *s)) == NULL)
			return (-1);
	*s = &tmp[i];
	return (0);
}

int			ft_expect(const char **s, const char *format, ...)
{
	char		c;
	const char	*tmp;
	va_list		argp;

	tmp = *s;
	va_start(argp, format);
	while ((c = *format++) != '\0')
	{
		if (c == '$' && (c = *format++))
		{
			if ((c == '$' && *tmp != c) ||
				(c == 'n' && read_number(&tmp, &format, argp)) ||
				(c == 'i' && read_identifier(&tmp, argp)) ||
				(c == '*' && read_wildcard(&tmp, &format, argp)))
				return (-1);
			continue ;
		}
		else if (c != *tmp)
			return (-1);
		++tmp;
	}
	va_end(argp);
	*s = tmp;
	return (0);
}
