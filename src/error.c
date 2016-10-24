/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:42:16 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/04 16:09:13 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/error.h"

/*
** Code-wide error object.
*/

static t_error	g_error;

static void		copy_string(int *len, char *arg)
{
	ft_strncpy(g_error.buffer + *len, arg, BUFF_SIZE - *len);
	*len = ft_strlen(g_error.buffer);
}

static void		copy_char(int *len, char arg)
{
	if (*len >= BUFF_SIZE)
		return ;
	g_error.buffer[(*len)++] = arg;
}

static void		copy_decimal(int *len, int arg)
{
	char	*new;

	new = ft_itoa(arg);
	if (new == NULL)
		return ;
	copy_string(len, new);
	free(new);
}

/*
** Returns the last error in the form on a string.
*/

char const		*get_error(void)
{
	if (g_error.active == 0)
		return ("Success");
	g_error.active = 0;
	return (g_error.buffer);
}

/*
** Sets the error active flag accompanied with a description string.
*/

int				set_error(char const *string, ...)
{
	int			len;
	va_list		argp;

	va_start(argp, string);
	ft_strcpy(g_error.buffer, "Error: ");
	len = ft_strlen(g_error.buffer);
	while (*string != '\0')
	{
		if (*string == '%' && ++string)
		{
			if (*string == 's' && ++string)
				copy_string(&len, va_arg(argp, char*));
			else if (*string == 'c' && ++string)
				copy_char(&len, va_arg(argp, int));
			else if (*string == 'd' && ++string)
				copy_decimal(&len, va_arg(argp, int));
			continue ;
		}
		if (len >= BUFF_SIZE)
			break ;
		g_error.buffer[len++] = *string++;
	}
	g_error.active = 1;
	va_end(argp);
	return (-1);
}
