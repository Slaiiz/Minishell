/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:50:23 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/06 18:09:35 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/input.h"

#include "error.h"
#include "execute.h"
#include "helpers.h"

/*
** Reads standard input for data to be processed.
** Upon reaching a newline, sends the whole line associated with it.
**  Returns 0 on success, or NON-ZERO on failure.
*/

int			read_input(char **out)
{
	t_buff	*buf;
	char	*ptr;
	ssize_t	size;
	char	t[32];

	buf = ft_bufnew();
	if (buf == NULL)
		return (set_error("memory allocation failed"));
	while ((size = read(STDIN_FILENO, t, 32)) >= 0)
	{
		if (ft_bufadd(buf, t, size))
			return (set_error("memory allocation failed"));
		if ((ptr = ft_memchr(buf->data, '\n', buf->len)) == NULL)
			continue ;
		size = (ptr - (char*)buf->data);
		*out = ft_strndup(buf->data, size + 1);
		if (*out == NULL)
			return (set_error("memory allocation failed"));
		(*out)[size] = '\0';
		ft_bufdel(&buf);
		return (0);
	}
	return (-1);
}

/*
** Given a line of text. Parses shell syntax out of it, executing commands
** encoded in it.
*/

int			process_input(char *line, char **envp)
{
	char	*tmp;
	int		argc;
	char	**argv;

	tmp = substitute_vars(line);
	if (tmp == NULL)
		return (set_error("memory allocation failed"));
	argv = ft_strsplit(tmp, ' ');
	free(tmp);
	if (argv == NULL)
		return (set_error("memory allocation failed"));
	argc = 0;
	while (argv[argc])
		++argc;
	if (argc > 0)
	{
		if (ft_strchr(argv[0], '/'))
		{
			if (execute_binary(argv, envp))
			{
				ft_arrdel((void***)&argv, argc, NULL);
				return (-1);
			}
		}
		else if (execute_builtin(argc, argv, envp))
		{
			ft_arrdel((void***)&argv, argc, NULL);
			return (-1);
		}
	}
	ft_arrdel((void***)&argv, argc, NULL);
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
