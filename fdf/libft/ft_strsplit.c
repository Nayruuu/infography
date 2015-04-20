/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 20:14:30 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/31 16:59:04 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	full_tab(char **tab, char const *s, char c)
{
	int			j;
	size_t		i;
	size_t		count;

	j = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		count = 0;
		while (s[i + count] != c && s[i + count])
			count++;
		tab[j] = ft_strsub(s, i, count);
		j++;
		i += count;
		while (s[i] == c && s[i])
			i++;
	}
}

static	int		count_words(char const *s, char c)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		count++;
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int			words;
	char		**new_tab;

	if (s && c)
	{
		words = count_words(s, c);
		if ((new_tab = (char**)malloc((words + 1) * sizeof(char*))))
		{
			full_tab(new_tab, s, c);
			new_tab[words] = '\0';
			return (new_tab);
		}
	}
	return (NULL);
}
