/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 16:56:25 by vchesnea          #+#    #+#             */
/*   Updated: 2017/10/10 18:03:25 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/execute.h"

#include "error.h"
#include "helpers.h"
#include "vars.h"

static t_builtin	g_builtins[7];

/*
** Looks for exec in the paths described by the PATH variable.
**  Returns 0 on success, or NONZERO on failure.
*/

static int			search_in_path(char *exec, char **out)
{
	int			index;
	char		**tmp;
	char		*join;
	char		**data;

	if ((data = ft_strsplit(get_var("PATH"), ':')) == NULL)
		return (set_error("memory allocation failed"));
	index = 0;
	*out = NULL;
	while (*out == NULL && data[index] != NULL)
	{
		if ((join = join_path(data[index], exec)) == NULL)
			return (set_error("memory allocation failed"));
		if (file_exists(join))
			*out = ft_strdup(join);
		free(join);
		++index;
	}
	tmp = data;
	while (*tmp)
		free(*tmp++);
	free(data);
	if (*out == NULL)
		return (set_error("executable not in path"));
	return (0);
}

/*
** Called at the initialization of the program.
** Installs the handlers for each interpretable command.
*/

void				initialize_builtins(void)
{
	DEFINE_BUILTIN(g_builtins[0], "cd", builtin_cd);
	DEFINE_BUILTIN(g_builtins[1], "env", builtin_env);
	DEFINE_BUILTIN(g_builtins[2], "exit", builtin_exit);
	DEFINE_BUILTIN(g_builtins[3], "help", builtin_help);
	DEFINE_BUILTIN(g_builtins[4], "pwd", builtin_pwd);
	DEFINE_BUILTIN(g_builtins[5], "setenv", builtin_setenv);
	DEFINE_BUILTIN(g_builtins[6], "unsetenv", builtin_unsetenv);
	DEFINE_BUILTIN(g_builtins[7], "echo", builtin_echo);
}

/*
** Forks a new instance of the process dedicated to executing
** a binary file pointed at by argv[0], then executes it,
** passing it the argv and envp arguments.
**  Returns 0 on success, or NONZERO on failure.
*/

int					execute_binary(char **argv, char **envp)
{
	if (!file_exists(argv[0]))
		return (set_error("no such file or directory: %s", argv[0]));
	if (access(argv[0], X_OK))
		return (set_error("permission denied: %s", argv[0]));
	if (fork() == 0)
	{
		if (execve(argv[0], argv, envp))
			return (set_error("could not execute binary: %s", argv[0]));
	}
	if (wait(NULL) == -1)
		return (set_error("failed to wait for child process"));
	return (0);
}

/*
** Executes the builtin command pointed at by argv[0].
** If not found, assume it is a binary executable instead.
**  Return 0 on success, or NONZERO on failure.
*/

int					execute_builtin(int argc, char **argv, char **envp)
{
	int		index;
	char	*path;

	index = 0;
	while (index < 8)
	{
		if (ft_strequ(argv[0], g_builtins[index].name))
		{
			g_builtins[index].func(argc, argv);
			return (0);
		}
		++index;
	}
	if (search_in_path(argv[0], &path))
		return (set_error("command not found: %s", argv[0]));
	free(argv[0]);
	argv[0] = path;
	if (execute_binary(argv, envp))
		return (-1);
	return (0);
}
