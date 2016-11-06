/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:45:30 by vchesnea          #+#    #+#             */
/*   Updated: 2016/11/01 15:55:55 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/libft_string.h"

#include "libft_memory.h"

static void	free_table(char ***table)
{
	char	***tmp;

	tmp = table;
	while (**tmp != NULL)
		free(*(*tmp++));
	free(*table);
	*table = NULL;
}

static int	next_word(const char **s, char c)
{
	int			len;
	const char	*tmp;

	len = 0;
	while (**s != '\0')
	{
		if (**s != c)
		{
			tmp = *s;
			while (**s != c)
			{
				if (**s == '\0')
					break ;
				++*s;
			}
			len = *s - tmp;
			break ;
		}
		++*s;
	}
	return (len);
}

char		**ft_strsplit(const char *s, char c)
{
	const char	*ptr;
	char		**tmp;
	char		**new;
	int			count;

	ptr = s;
	count = 0;
	while (next_word(&s, c))
		++count;
	new = ft_memalloc(sizeof(*new) * (count + 1));
	if (new == NULL)
		return (NULL);
	tmp = new;
	while ((count = next_word(&ptr, c)))
	{
		*tmp = ft_strsub(ptr - count, 0, count);
		if (*tmp == NULL)
		{
			free_table(&new);
			return (NULL);
		}
		++tmp;
	}
	*tmp = NULL;
	return (new);
}
