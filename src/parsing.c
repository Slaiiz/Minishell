/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:29:42 by vchesnea          #+#    #+#             */
/*   Updated: 2017/11/24 18:47:52 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/parsing.h"

#include "error.h"
#include "helpers.h"
#include "vars.h"

static int	read_quoted_string(const char **str, char **new)
{
	const char	*tmp;

	if (**str == '\"' && (tmp = ++(*str)))
	{
		while (*tmp != '\"')
			if (*tmp++ == '\0')
				return (set_error(ERR_EXPECTTOKEN, "\""));
	}
	else if (**str == '\'' && (tmp = ++(*str)))
	{
		while (*tmp != '\'')
			if (*tmp++ == '\0')
				return (set_error(ERR_EXPECTTOKEN, "\'"));
	}
	*new = ft_strndup(*str, tmp - *str);
	if (*new == NULL)
		return (set_error(ERR_NOMEMORY));
	*str = tmp + 1;
	return (0);
}

static int	read_tilde_operator(const char **str, char **new)
{
	const char	*tmp;

	tmp = *str + 1;
	while (*tmp != '\'' && *tmp != '\"')
	{
		if (*tmp == '\0' || ft_isblank(*tmp))
			break ;
		++tmp;
	}
	*new = ft_strnew(tmp - *str + ft_strlen(get_var("HOME")));
	if (*new == NULL)
		return (set_error(ERR_NOMEMORY));
	ft_strcat(*new, get_var("HOME"));
	ft_strncat(*new, *str + 1, tmp - (*str + 1));
	*str = tmp;
	return (0);
}

static int	read_single_word(const char **str, char **new)
{
	const char	*tmp;

	tmp = *str;
	if (*tmp == '~' && is_valid_tilde(tmp))
		return (read_tilde_operator(str, new));
	while (*tmp != '\'' && *tmp != '\"')
	{
		if (*tmp == '\0' || ft_isblank(*tmp))
			break ;
		++tmp;
	}
	*new = ft_strndup(*str, tmp - *str);
	if (*new == NULL)
		return (set_error(ERR_NOMEMORY));
	*str = tmp;
	return (0);
}

static int	turn_into_array(t_list **lst, char ***out)
{
	t_list	*tmp;
	size_t	len;

	tmp = *lst;
	len = ft_lstlen(tmp);
	*out = malloc((len + 1) * sizeof(char*));
	if (*out == NULL)
	{
		ft_lstfree(lst);
		return (set_error(ERR_NOMEMORY));
	}
	(*out)[len] = NULL;
	while (len--)
	{
		(*out)[len] = tmp->content;
		tmp = tmp->next;
	}
	ft_lstdel(lst, NULL);
	return (0);
}

/*
** Splits a string, with integrity of quoted texts preserved.
**  Returns an allocated string on success, or NULL on failure.
*/

int			parse_input_string(const char *str, char ***out)
{
	t_list		*lst;
	char		*new;

	lst = NULL;
	while (*str != '\0')
	{
		if (ft_isblank(*str) && ++str)
			continue ;
		if (*str == '\'' || *str == '\"')
		{
			if (read_quoted_string(&str, &new))
			{
				ft_lstfree(&lst);
				return (1);
			}
		}
		else if (read_single_word(&str, &new))
		{
			ft_lstfree(&lst);
			return (1);
		}
		ft_lstadd(&lst, ft_lstnew(new, ft_strlen(new)));
	}
	return (turn_into_array(&lst, out));
}
