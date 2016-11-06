/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 18:00:11 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/06 17:43:00 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

/*
** Called at the initialization of the program.
** Installs the handlers for each interpretable command.
*/

void	initialize_builtins(void);

/*
** Executes the builtin command pointed at by argv[0].
**  Return 0 on success, or NON-ZERO on failure.
*/

int		execute_builtin(int argc, char **argv, char **envp);

/*
** Forks a new instance of the process dedicated to executing
** a binary file pointed at by argv[0], then executes it,
** passing it arguments argv and envp.
**  Returns 0 on success, or NON-ZERO on failure.
*/

int		execute_binary(char **argv, char **envp);

#endif
