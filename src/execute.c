/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 16:56:25 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/26 19:08:33 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/execute.h"

static t_builtin	g_builtins[7];

static int			look_for_binary(char *exec)
{
	char	**data;
	char	*paths;
	char	*path;
	int		i;

	if (get_var("PATH", &paths))
		return ;
	data = ft_strsplit(paths, ' ');
	if (data == NULL)
		return (set_error("memory allocation failed"));
	i = 0;
	while (data[i] != NULL)
	{
		path = ft_strjoin(data[i], exec);
		if (path == NULL)
			return (set_error("memory allocation failed"));
		
	}
}

/*
** Called at the initialization of the program.
** Installs the handlers for each interpretable command.
*/

void				initialize_builtins(void)
{
	DEFINE_BUILTIN(0, "cd", builtin_cd);
	DEFINE_BUILTIN(1, "env", builtin_env);
	DEFINE_BUILTIN(2, "exit", builtin_exit);
	DEFINE_BUILTIN(3, "help", builtin_help);
	DEFINE_BUILTIN(4, "pwd", builtin_pwd);
	DEFINE_BUILTIN(5, "setenv", builtin_setenv);
	DEFINE_BUILTIN(6, "unsetenv", builtin_unsetenv);
}

/*
** Executes the builtin command pointed at by argv[0].
**  Return 0 on success, or NON-ZERO on failure.
*/

int					execute_builtin(int argc, char **argv, char **envp)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (!ft_strcmp(argv[0], g_builtins[i].name))
		{
			g_builtins[i].func(argc, argv);
			return (0);
		}
		++i;
	}
	if (look_for_binary(argv[0]))
		return (set_error("command not found"));
	if (execute_binary(argv, envp))
		return (-1);
	return (0);
}

/*
** Forks a new instance of the process dedicated to executing
** a binary file pointed at by argv[0], then executes it,
** passing it arguments argv and envp.
**  Returns 0 on success, or NON-ZERO on failure.
*/

int					execute_binary(char **argv, char **envp)
{
	if (access(argv[0], X_OK))
		return (set_error("permission denied: %s", argv[0]));
	if (fork() == 0)
	{
		if (execve(argv[0], argv, envp))
			return (set_error("could not execute binary"));
	}
	if (wait(NULL) == -1)
		return (set_error("failed to wait for child process"));
	return (0);
}
