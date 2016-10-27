/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:50:23 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/27 15:05:54 by vchesnea         ###   ########.fr       */
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

/*
** Reads standard input for data to be processed.
** Upon reaching a newline, sends the whole line associated with it.
**  Returns 0 on success, or NON-ZERO on failure.
*/

int			read_input(char const **out)
{
	static t_buff	buffer;
	static char		*data;
	int				bytes;

	if (data != NULL)
		free(data);
	while (1)
	{
		if ((bytes = fill_buffer(&buffer) < 1))
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
	return (ft_strlen(data));
}

/*
** Given a line of text. Parses shell syntax out of it, executing commands
** encoded in it.
*/

int			process_input(char const *line, char **envp)
{
	int		argc;
	char	**argv;

	argv = ft_strsplit(line, ' ');
	if (argv == NULL)
		return (set_error("memory allocation failed"));
	argc = ft_arraylen((void**)argv);
	if (argc > 0)
	{
		if (ft_strchr(argv[0], '/'))
		{
			if (execute_binary(argv, envp))
			{
				ft_arraydel((void***)&argv);
				return (-1);
			}
		}
		else if (execute_builtin(argc, argv, envp))
		{
			ft_arraydel((void***)&argv);
			return (-1);
		}
	}
	ft_arraydel((void***)&argv);
	return (0);
}

/*
** Sets-up the terminal for use in interactive mode.
*/

int			initialize_input(void)
{
	struct termios	attr;

	tcgetattr(0, &attr);
	attr.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &attr);
	return (0);
}
