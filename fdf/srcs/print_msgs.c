/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 16:17:04 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/10 01:20:36 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_msgs(t_env *env)
{
	mlx_string_put(MLX, WIN, 20, 30, 0xFFFFFFFF, CHOICE == 0 ? ISO : PAR);
	mlx_string_put(MLX, WIN, WIDTH - 120, 30, 0xFFFFFFFF, "RGB : ");
	mlx_string_put(MLX, WIN, WIDTH - 83, 30, 0xFF0000, ft_itoa(RED));
	mlx_string_put(MLX, WIN, WIDTH - 59, 30, 0xFF00FF00, ft_itoa(GREEN));
	mlx_string_put(MLX, WIN, WIDTH - 37, 30, 0xFF0000FF, ft_itoa(BLUE));
	mlx_string_put(MLX, WIN, WIDTH - 83, HEIGHT - 30, 0xFFFFFFFF, "COEFF : ");
	mlx_string_put(MLX, WIN, WIDTH - 32, HEIGHT - 30, 0xFFFFFFFF, ft_itoa(C));
	mlx_string_put(MLX, WIN, 25, HEIGHT - 30, 0xFFFFFFFF, "COEFFZ : ");
	mlx_string_put(MLX, WIN, 88, HEIGHT - 30, 0xFFFFFFFF, ft_itoa(COEFFZ));
}
