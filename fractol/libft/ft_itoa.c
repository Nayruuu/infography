/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:51:19 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/26 01:54:08 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*overflow(size_t n)
{
	char				*new;

	new = NULL;
	if (n > 0)
	{
		new = ft_strnew(10);
		ft_strcpy(new, "2147483647");
	}
	return (new);
}

static char				*convert(char *new, size_t n, int nbr_chars)
{
	new[nbr_chars] = '\0';
	if (n == 0)
		new[0] = '0';
	else
	{
		while (n)
		{
			new[nbr_chars - 1] = (n % 10) + 48;
			n = n - (n % 10);
			n = n / 10;
			nbr_chars--;
		}
	}
	return (new);
}

char					*ft_itoa(size_t n)
{
	size_t				mem;
	int					nbr_chars;
	char				*new;

	mem = n;
	nbr_chars = 0;
	while (mem)
	{
		mem = mem - (mem % 10);
		mem = mem / 10;
		nbr_chars++;
	}
	if (n == 2147483647)
		return (overflow(n));
	new = ft_strnew(nbr_chars);
	if (new)
	{
		new = convert(new, n, nbr_chars);
		return (new);
	}
	else
		return (NULL);
}
