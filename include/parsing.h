/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:30:23 by vchesnea          #+#    #+#             */
/*   Updated: 2017/11/24 18:07:27 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*
** Splits a string, with integrity of quoted texts preserved.
**  Returns an allocated string on success, or NULL on failure.
*/

int	parse_input_string(const char *str, char ***out);

#endif
