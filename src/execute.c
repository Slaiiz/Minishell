/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 16:56:25 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/30 11:22:32 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/execute.h"

#include "error.h"
#include "helpers.h"
#include "vars.h"

static t_builtin	g_builtins[7];

static int			search_in_path(char *exec, char **out)
{
	const char	*path;
	int			index;
	char		*join;
	char		**data;

	get_var("PATH", &path);
	data = ft_strsplit(path, ':');
	if (data == NULL)
		return (set_error("memory allocation failed"));
	index = 0;
	*out = NULL;
	while (*out == NULL && data[index] != NULL)
	{
		join = join_path(data[index], exec);
		if (join == NULL)
			return (set_error("memory allocation failed"));
		if (!access(join, X_OK))
			*out = ft_strdup(join);
		free(join);
		++index;
	}
	ft_arraydel((void***)&data);
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
}

/*
** Forks a new instance of the process dedicated to executing
** a binary file pointed at by argv[0], then executes it,
** passing it the argv and envp arguments.
**  Returns 0 on success, or NON-ZERO on failure.
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
**  Return 0 on success, or NON-ZERO on failure.
*/

int					execute_builtin(int argc, char **argv, char **envp)
{
	char	*path;
	int		index;

	index = 0;
	while (index < 7)
	{
		if (!ft_strcmp(argv[0], g_builtins[index].name))
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
