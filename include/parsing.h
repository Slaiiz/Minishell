/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:30:23 by vchesnea          #+#    #+#             */
/*   Updated: 2017/11/20 10:30:24 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*
** Splits a string, with integrity of quoted texts preserved.
**  Returns an allocated string on success, or NULL on failure.
*/

char	**parse_input_string(char const *str);

#endif
