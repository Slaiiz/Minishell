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
	ft_printf("\n");
	print_prompt();
}

static int	run_interactive_mode(void)
{
	const char	**args;
	const char	*line;
	ssize_t		bytes;

	while (1)
	{
		print_prompt();
		bytes = read_input(&line);
		if (bytes < 1)
			break ;
	}
	if (bytes < 0)
		return (-1);
	return (0);
}

static int	parse_flags(t_flaglist **out, int argc, char **argv)
{
	int	error;
	int	port;

	if (flag_add(out, 'h', "help", FLAG_TYPE_HOOK, help))
		return (set_error("memory allocation failed"));
	error = flag_parse(*out, argc, argv);
	if (error == FLAG_ERROR_NOMATCH)
		return (set_error("unrecognized flag"));
	if (error == FLAG_ERROR_BADSYNTAX)
		return (set_error("bad flag syntax"));
	flag_free(out);
	return (0);
}

static int	setup_session(char **envp)
{
	char	*value;
	char	*key;

	if (signal(SIGINT, handle_signal))
		return (set_error("could not setup signals"));
	if (set_var("PS1", DEFAULT_PROMPT))
		return (-1);
	while (*envp != NULL)
	{
		if (ft_expect((const char**)envp, "$*=$*", &key, &value))
			return (set_error("malformed key/value pair"));
		if (set_var(key, value))
			return (-1);
		++envp;
	}
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
	if (run_interactive_mode())
	{
		ft_printf("#!fd=2^%s\n", get_error());
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
