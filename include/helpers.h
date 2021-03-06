/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 10:06:07 by vchesnea          #+#    #+#             */
/*   Updated: 2017/11/24 15:33:25 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

/*
** Joins s1 and s2 together to form a path string.
** The string is dynamically allocated and must be freed by the user.
**  Returns a pointer to the new string on success, or NULL on failure.
*/

char	*join_path(const char *s1, const char *s2);

/*
** Emits an (incomplete) assumption about whether the file exists or not.
**  Returns 1 when condition is met, or 0 in all other cases.
*/

int		file_exists(const char *path);

/*
** Replaces every occurence of $[a-zA-Z]+ with the value of the environment
** variable refered by it.
*/

char	*substitute_input(const char *str);

/*
** Returns whether the tilde pointed at by str should be substitued.
*/

int		is_valid_tilde(const char *str);

#endif
