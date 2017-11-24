/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 13:41:13 by vchesnea          #+#    #+#             */
/*   Updated: 2017/11/24 16:18:00 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/output.h"

#include "vars.h"

/*
** Executed on command-line flag '-h --help', prints help and quits.
*/

void	print_help(void)
{
	ft_printf("Usage: ./minishell [-hv] [--help --version]\n");
	exit(EXIT_SUCCESS);
}

/*
** Executed on command-line flag '-v --version', prints build version.
** Only for the show, ain't gonna change anytime soon.
*/

void	print_version(void)
{
	ft_printf("Minishell, version 1.0.0\n");
	exit(EXIT_SUCCESS);
}

/*
** Called each time to mark the beginning of a command.
** Prints a customizable prompt inherited from environment
** variable 'PS1'.
*/

void	print_prompt(void)
{
	char const	*string;

	string = get_var("PS1");
	if (ft_strequ(string, ""))
	{
		ft_printf("%s ", DEFAULT_PROMPT);
		return ;
	}
	ft_printf("%s ", string);
}
