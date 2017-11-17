/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:50:23 by vchesnea          #+#    #+#             */
/*   Updated: 2017/10/10 18:03:24 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/input.h"

#include "error.h"
#include "execute.h"
#include "helpers.h"

/*
** Does the job of choosing what to execute and how.
**  Returns 0 on success, or NONZERO on failure.
*/

static int	carry_execution(int argc, char **argv, char **envp)
{
	if (argc > 0)
	{
		if (ft_strchr(argv[0], '/'))
		{
			if (execute_binary(argv, envp))
				return (1);
		}
		else if (execute_builtin(argc, argv, envp))
			return (1);
	}
	return (0);
}

/*
** Reads standard input for data to be processed.
** Upon reaching a newline, sends the whole line associated with it.
**  Returns 0 on success, or NONZERO on failure.
*/

int			read_input(char **out)
{
	char	t[32];
	char	*ptr;
	t_buff	*buf;
	ssize_t	size;

	buf = ft_bufnew();
	if (buf == NULL)
		return (set_error(ERR_NOMEMORY));
	while ((size = read(STDIN_FILENO, t, 32)) > 0)
	{
		if (ft_bufadd(buf, t, size))
			return (set_error(ERR_NOMEMORY));
		if ((ptr = ft_memchr(buf->data, '\n', buf->len)) == NULL)
			continue ;
		size = (ptr - (char*)buf->data);
		*out = ft_strndup(buf->data, size + 1);
		if (*out == NULL)
			return (set_error(ERR_NOMEMORY));
		(*out)[size] = '\0';
		ft_bufdel(&buf);
		return (0);
	}
	ft_bufdel(&buf);
	return (1);
}

/*
** Given a line of text. Parses shell syntax out of it, executing commands
** encoded in it.
*/

int			process_input(char *line, char **envp)
{
	int		argc;
	char	*tmp;
	char	**argv;

	tmp = substitute_vars(line);
	if (tmp == NULL)
		return (set_error(ERR_NOMEMORY));
	argv = ft_strsplit(tmp, ' ');
	free(tmp);
	if (argv == NULL)
		return (set_error(ERR_NOMEMORY));
	argc = 0;
	while (argv[argc])
		++argc;
	if (carry_execution(argc, argv, envp))
	{
		ft_arrdel((void***)&argv, argc, NULL);
		return (1);
	}
	ft_arrdel((void***)&argv, argc, NULL);
	return (0);
}
