/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 03:43:42 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/23 03:54:43 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_line(char **stock)
{
	int		i;

	i = 0;
	while (stock[i])
	{
		ft_strdel(&stock[i]);
		i++;
	}
	free(stock);
	stock = NULL;
}