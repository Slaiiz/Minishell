/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:50:23 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/04 16:50:24 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/input.h"

static int	extend_buffer(t_buff *buffer)
{
	char	*new;

	buffer->size += BUFF_SIZE;
	new = malloc(sizeof(*new) * (buffer->size + 1));
	if (new == NULL)
		return (set_error("memory allocation failed"));
	if (buffer->data != NULL)
	{
		ft_memcpy(new, buffer->data, buffer->len);
		free(buffer->data);
	}
	buffer->data = new;
	return (0);
}

static int	fill_buffer(t_buff *buffer)
{
	ssize_t	bytes;

	if (!(buffer->len % BUFF_SIZE) && extend_buffer(buffer))
		return (-1);
	bytes = read(0, buffer->data + buffer->len, buffer->size - buffer->len);
	if (bytes < 0)
		return (set_error("could not read stdin"));
	buffer->len += bytes;
	buffer->data[buffer->len] = '\0';
	return ((int)bytes);
}

int			read_input(char const **out)
{
	static t_buff	buffer;
	static char		*data;
	ssize_t			bytes;

	if (data != NULL)
		free(data);
	while (1)
	{
		if (fill_buffer(&buffer) < 1)
			return (-1);
		data = ft_strchr(buffer.data, '\n');
		if (data == NULL)
			continue ;
		*out = ft_strsub(buffer.data, 0, (data - buffer.data));
		ft_memcpy(buffer.data, &data[1], buffer.len + buffer.data - data);
		buffer.len -= &data[1] - buffer.data;
		break ;
	}
	data = (char*)*out;
	return (bytes);
}

int			process_input(char const *line)
{
	int		len;
	char	**args;

	args = ft_strsplit(line, ' ');
	if (args == NULL)
		return (set_error("memory allocation failed"));
	len = ft_arraylen((void**)args);
	if (len < 1)
		return (0);
	if (!ft_strcmp(args[0], "help"))
		builtin_help();
	else if (!ft_strcmp(args[0], "pwd"))
		builtin_pwd();
	else if (!ft_strcmp(args[0], "exit"))
		builtin_exit();
	else if (!ft_strcmp(args[0], "env"))
		builtin_env();
	else if (!ft_strcmp(args[0], "setenv"))
		builtin_setenv(len, args);
	else if (!ft_strcmp(args[0], "unsetenv"))
		builtin_unsetenv(len, args);
	else
	{
		set_error("command not found");
		ft_arraydel((void***)&args);
		return (-1);
	}
	ft_arraydel((void***)&args);
	ft_printf("args = %p\n", args);
	return (0);
}
