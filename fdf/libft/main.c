/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 01:52:27 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/23 01:54:49 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int main(void)
{
	char *line;
	int fd = open(0, O_RDONLY);
	while (get_next_line(0, &line) > 0)
		ft_putendl(line);
	return (0);
}
