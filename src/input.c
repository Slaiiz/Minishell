/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:50:23 by vchesnea          #+#    #+#             */
/*   Updated: 2017/11/24 18:50:20 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/input.h"

#include "vars.h"
#include "error.h"
#include "execute.h"
#include "helpers.h"
#include "parsing.h"

static int	combine_var(const t_entry *var, char **out)
{
	char		*tmp;
	size_t		size;

	size = ft_strlen(var->key) + ft_strlen(var->value);
	if ((tmp = ft_strnew(size + 1 + 1)) == NULL)
		return (set_error(ERR_NOMEMORY));
	ft_strcat(tmp, var->key);
	ft_strcat(tmp, "=");
	ft_strcat(tmp, var->value);
	*out = tmp;
	return (0);
}

static int	turn_into_array(const t_entry *vars, char ***out)
{
	char			**bak;
	size_t			size;
	const t_entry	*tmp;

	size = 0;
	tmp = vars;
	while (tmp != NULL && ++size)
		tmp = tmp->next;
	*out = malloc((size + 1) * sizeof(char*));
	if (*out == NULL)
		return (set_error(ERR_NOMEMORY));
	bak = *out;
	while (vars != NULL)
	{
		if (combine_var(vars, bak++))
			return (1);
		vars = vars->next;
	}
	*bak = NULL;
	return (0);
}

/*
** Does the job of choosing what to execute and how.
** FIXME: Mmm ... That looks real nasty, eh?
**  Returns 0 on success, or NONZERO on failure.
*/

static int	carry_execution(int argc, char **argv)
{
	int		retval;
	char	**envp;
	char	**tmp;

	retval = 0;
	envp = NULL;
	turn_into_array(get_vars(), &envp);
	if (envp == NULL)
		return (set_error(ERR_NOMEMORY));
	if (argc > 0)
	{
		if (ft_strchr(argv[0], '/'))
		{
			if (execute_binary(argv, envp))
				retval = 1;
		}
		else if (execute_builtin(argc, argv, envp))
			retval = 1;
	}
	tmp = envp;
	while (*tmp)
		++tmp;
	ft_arrdel((void***)&envp, tmp - envp, NULL);
	return (retval);
}

/*
** Reads standard input for data to be loaded in the command buffer.
**  Returns 0 on success, or NONZERO on failure.
*/

int			read_input(t_buff *buff, char **out, char *delim)
{
	char	c;
	ssize_t	size;
	char	*ptr;

	if (!(ptr = ft_memchr(buff->data, ';', buff->len)))
	{
		while (!(ptr = ft_memchr(buff->data, '\n', buff->len)))
		{
			if ((size = read(STDIN_FILENO, &c, 1)) <= 0)
				return (set_error(ERR_READFAILED));
			if (ft_bufadd(buff, &c, size))
				return (set_error(ERR_NOMEMORY));
			if ((ptr = ft_memchr(buff->data, ';', buff->len)))
				break ;
		}
	}
	size = ptr - (char*)buff->data;
	*out = ft_bufdup(buff, size + 1);
	if (*out == NULL)
		return (set_error(ERR_NOMEMORY));
	*delim = (*out)[size];
	(*out)[size] = '\0';
	return (0);
}

/*
** Given a line of text. Parses shell syntax out of it, executing commands
** encoded in it.
*/

int			process_input(char *line)
{
	int		argc;
	char	*tmp;
	char	**argv;

	tmp = substitute_input(line);
	if (tmp == NULL)
		return (1);
	if (parse_input_string(tmp, &argv))
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	argc = 0;
	while (argv[argc])
		++argc;
	if (carry_execution(argc, argv))
	{
		ft_arrdel((void***)&argv, argc, NULL);
		return (1);
	}
	ft_arrdel((void***)&argv, argc, NULL);
	return (0);
}
