/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 13:41:13 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/09 13:41:14 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/output.h"

void	print_help(void)
{
	ft_printf("Usage: ./minishell [-h] [--help]\n");
	exit(EXIT_SUCCESS);
}

void	print_prompt(void)
{
	char const	*string;

	if (get_var("PS1", &string))
	{
		ft_printf("%s", DEFAULT_PROMPT);
		return ;
	}
	ft_printf("%s", string);
}
