/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 15:51:24 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/30 17:44:51 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/main.h"

#include "error.h"
#include "execute.h"
#include "helpers.h"
#include "input.h"
#include "output.h"
#include "vars.h"

static void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\n");
		print_prompt();
	}
}

static int	run_interactive_mode(char *exec, char **envp)
{
	char	*line;

	while (1)
	{
		print_prompt();
		if (read_input(&line))
			return (-1);
		if (process_input(line, envp))
			ft_printf("#!fd=2^%s: %s\n", exec, get_error());
		free(line);
	}
	return (0);
}

static int	parse_flags(t_flaglist **out, int argc, char **argv)
{
	int	error;

	*out = NULL;
	if (libflag_add(out, 'h', "help", FLAG_TYPE_HOOK, print_help))
		return (set_error("memory allocation failed"));
	error = libflag_parse(*out, argc, argv);
	if (error == FLAG_ERROR_NOMATCH)
		return (set_error("unrecognized flag"));
	if (error == FLAG_ERROR_BADSYNTAX)
		return (set_error("bad flag syntax"));
	libflag_free(out);
	return (0);
}

static int	setup_session(char **envp)
{
	char	*value;
	char	*key;

	initialize_builtins();
	if (signal(SIGINT, handle_signal))
		return (set_error("could not setup signals"));
	while (*envp != NULL)
	{
		if (ft_expect((char const**)envp, "$*=$*", &key, &value))
			return (set_error("malformed key/value pair"));
		if (set_var(key, value))
			return (-1);
		++envp;
	}
	set_var("TERM", "xterm-256color");
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
	t_flaglist	*flags;

	if (parse_flags(&flags, argc, argv))
	{
		ft_printf("#!fd=2^%s: %s\n", argv[0], get_error());
		return (EXIT_FAILURE);
	}
	if (setup_session(envp))
	{
		ft_printf("#!fd=2^%s: %s\n", argv[0], get_error());
		return (EXIT_FAILURE);
	}
	if (run_interactive_mode(argv[0], envp))
	{
		ft_printf("#!fd=2^%s: %s\n", argv[0], get_error());
		return (EXIT_FAILURE);
	}
	ft_printf("Bye!\n");
	return (EXIT_SUCCESS);
}
