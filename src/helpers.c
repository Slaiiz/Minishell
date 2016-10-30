/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 10:03:55 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/30 10:14:44 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/helpers.h"

/*
** Joins s1 and s2 together to form a path string.
** The string is dynamically allocated and must be freed by the user.
**  Returns a pointer to the new string on success, or NULL on failure.
*/

char	*join_path(const char *s1, const char *s2)
{
	size_t	len;
	char	*new;

	len = ft_strlen(s1);
	if (len && s1[len - 1] == '/')
		--len;
	new = malloc(sizeof(*new) * len + ft_strlen(s2) + 2);
	if (new == NULL)
		return (NULL);
	ft_strncpy(new, s1, len);
	new[len] = '/';
	ft_strcpy(new + len + 1, s2);
	return (new);
}

/*
** Emits an (incomplete) assumption about whether the file exists or not.
**  Returns 1 when condition is met, or 0 in all other cases.
*/

int		file_exists(const char *path)
{
	struct stat stats;

	if (stat(path, &stats))
		return (0);
	return (1);
}
