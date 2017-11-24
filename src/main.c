/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 15:51:24 by vchesnea          #+#    #+#             */
/*   Updated: 2017/11/24 17:04:56 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/main.h"

#include "error.h"
#include "execute.h"
#include "helpers.h"
#include "input.h"
#include "output.h"
#include "vars.h"

pid_t		g_child;

/*
** Called whenever a handled signal is triggered.
** SIGINT: Interrupt execution.
*/

static void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		if (g_child)
		{
			kill(g_child, SIGINT);
			return ;
		}
		ft_printf("\n");
		print_prompt();
	}
}

/*
** Runs the program in an infinite loop, no way out once in.
*/

static int	run_interactive_mode(char *exec)
{
	t_buff		*buff;
	char		*line;
	char		delim;

	if ((buff = ft_bufnew()) == NULL)
		return (set_error(ERR_NOMEMORY));
	print_prompt();
	while (1)
	{
		if (read_input(buff, &line, &delim))
			return (1);
		if (process_input(line))
			ft_printf("#!fd=2^%s: %s\n", exec, get_error());
		if (delim == '\n')
			print_prompt();
		ft_strdel(&line);
	}
	return (1);
}

/*
** Parses behavior-modifying command-line arguments.
*/

static int	parse_flags(int argc, char **argv)
{
	int			error;
	t_flaglist	*flags;

	flags = NULL;
	if (flag_add(&flags, "h:help", FLAG_TYPE_HOOK, print_help))
		return (set_error(ERR_NOMEMORY));
	if (flag_add(&flags, "v:version", FLAG_TYPE_HOOK, print_version))
		return (set_error(ERR_NOMEMORY));
	error = flag_parse(flags, argc, argv);
	if (error == FLAG_ERROR_NOMATCH)
		return (set_error(ERR_UNKNOWNFLAG));
	if (error == FLAG_ERROR_BADSYNTAX)
		return (set_error(ERR_BADFLAGSTX));
	flag_free(&flags);
	return (0);
}

/*
** Sets-up the builtin commands, the signals.
** Inherits the parent process' environment.
** Increments $SHLVL variable.
**  Returns 0 on success, or NONZERO on failure.
*/

static int	setup_session(char **envp)
{
	char	*key;
	char	*tmp;
	char	*shlvl;
	char	*value;

	initialize_builtins();
	if (signal(SIGINT, handle_signal))
		return (set_error(ERR_SIGNALFAILED));
	while (*envp != NULL)
	{
		tmp = *envp;
		if (ft_expect((char const**)&tmp, "$*=$*", &key, &value))
			return (set_error(ERR_MALFORMEDKV));
		if (set_var(key, value))
			return (1);
		free(value);
		free(key);
		++envp;
	}
	shlvl = ft_itoa(ft_atoi(get_var("SHLVL")) + 1);
	if (set_var("SHLVL", shlvl))
		return (1);
	free(shlvl);
	return (0);
}

/*
** Program entry point. First parse the command-line flags, then
** initialize the builtin commands, hook up to the SIGINT signal,
** retrieve and set-up the inherited environment variables.
** Finally, enter the main program loop.
*/

int			main(int argc, char **argv, char **envp)
{
	if (parse_flags(argc, argv))
	{
		ft_printf("#!fd=2^%s: %s\n", argv[0], get_error());
		return (EXIT_FAILURE);
	}
	if (setup_session(envp))
	{
		ft_printf("#!fd=2^%s: %s\n", argv[0], get_error());
		return (EXIT_FAILURE);
	}
	if (run_interactive_mode(argv[0]))
	{
		ft_printf("#!fd=2^%s: %s\n", argv[0], get_error());
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
