/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 10:03:55 by vchesnea          #+#    #+#             */
/*   Updated: 2016/10/30 18:12:10 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/helpers.h"

#include "error.h"
#include "vars.h"

/*
** Replaces every occurence of $[a-zA-Z]+ with the value of the environment
** variable refered by it.
*/

char		*substitute_vars(const char *string)
{
	t_buff		*buf;
	const char	*ptr;
	char		*tmp;

	buf = ft_bufnew(32);
	if (buf == NULL)
		return (NULL);
	while ((ptr = ft_strchr(string, '$')) && ++ptr)
	{
		if (ft_bufadd(buf, string, ptr - string - 1))
			return (NULL);
		string = ptr;
		while (ft_isalnum(*ptr) || *ptr == '_')
			++ptr;
		tmp = ft_strsub(string, 0, ptr - string);
		if (tmp == NULL)
			return (NULL);
		ft_bufadd(buf, get_var(tmp), ft_strlen(get_var(tmp)));
		string = ptr;
		free(tmp);
	}
	if (ft_bufadd(buf, string, ft_strchr(string, '\0') - string + 1))
		return (NULL);
	if ((tmp = ft_strdup(buf->data)) == NULL)
		return (NULL);
	ft_bufdel(&buf);
	return (tmp);
}

/*
** Joins s1 and s2 together to form a path string.
** The string is dynamically allocated and must be freed by the user.
**  Returns a pointer to the new string on success, or NULL on failure.
*/

char		*join_path(const char *s1, const char *s2)
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

int			file_exists(const char *path)
{
	struct stat stats;

	if (stat(path, &stats))
		return (0);
	return (1);
}
