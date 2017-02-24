/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 15:51:24 by vchesnea          #+#    #+#             */
/*   Updated: 2017/02/14 14:28:30 by vchesnea         ###   ########.fr       */
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
			continue ;
		if (process_input(line, envp))
			ft_printf("#!fd=2^%s: %s\n", exec, get_error());
		free(line);
	}
	free_vars();
	return (0);
}

static int	parse_flags(int argc, char **argv)
{
	int			error;
	t_flaglist	*flags;

	flags = NULL;
	if (flag_add(&flags, 'h', "help", FLAG_TYPE_HOOK, print_help))
		return (set_error("memory allocation failed"));
	error = flag_parse(flags, argc, argv);
	if (error == FLAG_ERROR_NOMATCH)
		return (set_error("unrecognized flag"));
	if (error == FLAG_ERROR_BADSYNTAX)
		return (set_error("bad flag syntax"));
	flag_free(&flags);
	return (0);
}

static int	setup_session(char **envp)
{
	char	*key;
	char	*tmp;
	char	*value;

	initialize_builtins();
	if (signal(SIGINT, handle_signal))
		return (set_error("could not setup signals"));
	while (*envp != NULL)
	{
		tmp = *envp;
		if (ft_expect((char const**)&tmp, "$*=$*", &key, &value))
			return (set_error("malformed key/value pair"));
		if (set_var(key, value))
			return (-1);
		free(value);
		free(key);
		++envp;
	}
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
	if (run_interactive_mode(argv[0], envp))
	{
		ft_printf("#!fd=2^%s: %s\n", argv[0], get_error());
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
