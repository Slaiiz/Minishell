/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 16:56:25 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/14 16:56:27 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/execute.h"

static t_builtin	g_builtins[7];

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

int					execute_builtin(int argc, char **argv)
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
	return (set_error("command not found"));
}

int					execute_binary(int argc, char **argv, char **envp)
{
	pid_t	pid;

	if (access(argv[0], X_OK))
		return (set_error("permission denied: %s", argv[0]));
	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, envp))
			return (set_error("could not execute binary"));
	}
	if (wait(NULL) == -1)
		return (set_error("failed to wait for child process"));
	return (0);
}
