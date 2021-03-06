/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 10:03:55 by vchesnea          #+#    #+#             */
/*   Updated: 2017/11/24 16:46:57 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/helpers.h"

#include "error.h"
#include "vars.h"

/*
** Handles a single var substitution then advances the given pointer.
**  Returns 0 on success, or NONZERO on failure.
*/

static int	substitute_single(t_buff *buf, const char **pos, const char *ptr)
{
	char	*tmp;

	*pos = ptr;
	while (ft_isalnum(*ptr) || *ptr == '_')
		++ptr;
	if ((tmp = ft_strsub(*pos, 0, ptr - *pos)) == NULL)
		return (set_error(ERR_NOMEMORY));
	if (ft_bufadd(buf, get_var(tmp), ft_strlen(get_var(tmp))))
		return (set_error(ERR_NOMEMORY));
	*pos = ptr;
	free(tmp);
	return (0);
}

/*
** Replaces every occurence of \$[a-zA-Z_]+ with the value
** of the environment variable reffered to by it.
**  Returns the substitued string on success, or NULL on failure.
*/

char		*substitute_input(const char *string)
{
	char		*tmp;
	t_buff		*buf;
	const char	*ptr;

	if ((buf = ft_bufnew()) == NULL)
		return (NULL);
	while ((ptr = ft_strchr(string, '$')) && ++ptr)
	{
		if (ft_bufadd(buf, string, ptr - string - 1))
			return (NULL);
		if (substitute_single(buf, &string, ptr))
			return (NULL);
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
	new = malloc(len + ft_strlen(s2) + 2);
	if (new == NULL)
		return (NULL);
	ft_strncpy(new, s1, len);
	new[len] = '/';
	ft_strcpy(new + len + 1, s2);
	return (new);
}

/*
** Returns whether the tilde pointed at by str should be substitued.
*/

int			is_valid_tilde(const char *str)
{
	if (*str == '~' && ++str)
	{
		if (*str == '\0' || *str == '/' || ft_isblank(*str))
			return (1);
	}
	return (0);
}

/*
** Emits an (incomplete) assumption about whether the file exists or not.
**  Returns 1 when condition is met, or 0 in all other cases.
*/

int			file_exists(const char *path)
{
	struct stat	stats;

	if (stat(path, &stats))
		return (0);
	return (1);
}
