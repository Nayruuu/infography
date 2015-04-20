/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 00:45:54 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/10 18:02:16 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_menu(void)
{
	ft_putendl("Menu :");
	ft_putendl("***************");
	ft_putendl("ECHAP / CLEAR : QUIT");
	ft_putendl("= : ISOMETRIC");
	ft_putendl("/ : PARALLEL");
	ft_putendl("Q : +R  A : -R");
	ft_putendl("W : +G  S : -G");
	ft_putendl("E : +B  D : -B");
	ft_putendl("7 : +ANGLEX");
	ft_putendl("9 : -ANGLEX");
	ft_putendl("1 : +ANGLEZ");
	ft_putendl("3 : -ANGLEZ");
	ft_putendl("8 : UP");
	ft_putendl("2 : DOWN");
	ft_putendl("4 : LEFT");
	ft_putendl("6 : RIGHT");
	ft_putendl("5 : CENTER");
	ft_putendl("0 : ORIGIN");
	ft_putendl("- : DEZOOM");
	ft_putendl("+ : ZOOM");
}
