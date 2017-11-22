/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:43:36 by vchesnea          #+#    #+#             */
/*   Updated: 2017/11/22 17:24:10 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

/*
** Reads standard input for data to be processed.
** Upon reaching a newline, sends the whole line associated with it.
**  Returns 0 on success, or NON-ZERO on failure. On failure an error is set.
*/

int	read_input(t_buff *buff, char **out, char *delim);

/*
** Given a line of text. Parses shell syntax out of it, executing commands
** encoded in it.
**  Returns 0 on success, or NON-ZERO on failure. On failure an error is set.
*/

int	process_input(char *line, char **envp);

#endif
