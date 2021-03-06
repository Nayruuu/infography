/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 15:53:56 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/04 15:57:06 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 		ft_ispunct(int c)
{
	if ((c >= 041 && c <= 047) || (c >= 050 && c <= 057) ||
		(c >= 072 && c <= 077) || (c >= 133 && c <= 137) ||
		(c >= 173 && c <= 176) || c == 100 || c == 140)
		return (1);
	else
		return (0);
}
