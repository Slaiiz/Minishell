/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 13:41:13 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/29 19:02:10 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/output.h"

/*
** Executed on command-line flag '-h --help', prints help and quits.
*/

void	print_help(void)
{
	ft_printf("Usage: ./minishell [-h] [--help]\n");
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

	if (get_var("PS1", &string))
	{
		ft_printf("%s ", DEFAULT_PROMPT);
		return ;
	}
	ft_printf("%s ", string);
}
