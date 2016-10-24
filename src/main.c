/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 15:51:24 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/04 15:51:25 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/main.h"

static void	handle_signal(int sig)
{
	sig = 2;
	ft_printf("\n");
	print_prompt();
}

static int	run_interactive_mode(char **envp)
{
	char const	*line;
	ssize_t		bytes;

	while (1)
	{
		print_prompt();
		bytes = read_input(&line);
		if (bytes < 1)
			break ;
		if (process_input(line, envp))
			ft_printf("#!fd=2^%s\n", get_error());
	}
	if (bytes < 0)
		return (-1);
	return (0);
}

static int	parse_flags(t_flaglist **out, int argc, char **argv)
{
	int	error;

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
	if (set_var("PS1", DEFAULT_PROMPT))
		return (-1);
	return (0);
}

int			main(int argc, char **argv, char **envp)
{
	t_flaglist	*flags;

	if (parse_flags(&flags, argc, argv))
	{
		ft_printf("#!fd=2^%s\n", get_error());
		return (EXIT_FAILURE);
	}
	if (setup_session(envp))
	{
		ft_printf("#!fd=2^%s\n", get_error());
		return (EXIT_FAILURE);
	}
	if (run_interactive_mode(envp))
	{
		ft_printf("#!fd=2^%s\n", get_error());
		return (EXIT_FAILURE);
	}
	ft_printf("Bye!\n");
	return (EXIT_SUCCESS);
}
