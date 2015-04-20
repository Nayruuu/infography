/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 14:54:31 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/10 18:14:19 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_point				project_para(t_env *env, t_point p)
{
	double			dx;
	double			dy;
	int				dz;
	t_point			new;
	const double	cste = sqrt(2) / 2;

	p.x = C * p.x;
	p.y = C * p.y;
	p.z = COEFFZ * (p.z * OFF.z) / 2;
	dz = p.z;
	p.y = p.y * cos(ANGLEX) + sin(ANGLEX) * p.z;
	p.z = p.z * cos(ANGLEX) - sin(ANGLEX) * p.y;
	p.x = p.x * cos(ANGLEZ) - sin(ANGLEZ) * p.y;
	p.y = p.x * sin(ANGLEZ) + cos(ANGLEZ) * p.y;
	dx = cste + p.x;
	dy = p.y + (cste * p.z / 2);
	new.x = lround(dx) + OFF.x;
	new.y = lround(dy) + OFF.y;
	new.z = dz;
	return (new);
}

t_point				project_iso(t_env *env, t_point p)
{
	double			dx;
	double			dy;
	int				dz;
	t_point			new;
	const double	cste = sqrt(2) / 2;

	p.x = C * p.x;
	p.y = C * p.y;
	p.z = COEFFZ * (p.z * OFF.z) / 2;
	dz = p.z;
	p.y = p.y * cos(ANGLEX) + sin(ANGLEX) * p.z;
	p.z = p.z * cos(ANGLEX) - sin(ANGLEX) * p.y;
	p.x = p.x * cos(ANGLEZ) - sin(ANGLEZ) * p.y;
	p.y = p.x * sin(ANGLEZ) + cos(ANGLEZ) * p.y;
	dx = cste * p.x - cste * p.y;
	dy = 0 - p.z + (cste / 2 * p.x) + (cste / 2 * p.y);
	new.x = lround(dx) + OFF.x;
	new.y = lround(dy) + OFF.y;
	new.z = dz;
	return (new);
}

t_point				choice(t_env *env, t_point p)
{
	t_point			t_p;

	if (CHOICE == 0)
		t_p = project_iso(env, p);
	else if (CHOICE == 1)
		t_p = project_para(env, p);
	return (t_p);
}
