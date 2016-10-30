/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:50:32 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/30 17:44:21 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

/*
** Reads standard input for data to be processed.
** Upon reaching a newline, sends the whole line associated with it.
**  Returns 0 on success, or NON-ZERO on failure. On failure an error is set.
*/

int	read_input(char **out);

/*
** Given a line of text. Parses shell syntax out of it, executing commands
** encoded in it.
**  Returns 0 on success, or NON-ZERO on failure. On failure an error is set.
*/

int	process_input(char *line, char **envp);

/*
** Sets-up the terminal for use in interactive mode.
*/

int	initialize_input(void);

#endif
