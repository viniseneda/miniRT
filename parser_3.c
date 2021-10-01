/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:44:40 by vvarussa          #+#    #+#             */
/*   Updated: 2021/10/01 10:52:24 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_char(t_parsing p, char c)
{
	if (**p.s != c)
		line_error("wrong syntax", p);
	*p.s = *p.s + 1;
	skip_space(p);
}

double	r_double_loop(t_parsing p)
{
	double	n;
	int		z;

	z = 0;
	n = 0;
	if (!ft_isdigit(**p.s))
		line_error("Lacking a number", p);
	while (ft_isdigit(**p.s))
	{
		n = n * 10 + (**p.s - '0');
		*p.s = *p.s + 1;
		if (**p.s == '.' || z)
		{
			if (!z)
				*p.s = *p.s + 1;
			z++;
		}
	}
	if (z)
		return (n / pow(10, z - 1));
	return (n);
}

double	parse_double(t_parsing p)
{
	double	n;
	bool	minus;

	minus = false;
	if (**p.s == '-')
	{
		minus = true;
		*p.s = *p.s + 1;
	}
	n = r_double_loop(p);
	if (minus)
		n *= -1;
	skip_space(p);
	return (n);
}

t_dunit	parse_vector(t_parsing p)
{
	t_dunit	u;

	u.x = parse_double(p);
	parse_char(p, ',');
	u.y = parse_double(p);
	parse_char(p, ',');
	u.z = parse_double(p);
	if ((u.x < -1 || u.x > 1) || (u.y < -1 || u.y > 1) || (u.z < -1 || u.z > 1))
		line_error("it has to be a normalized vector", p);
	u.w = 0;
	return (u);
}

t_dunit	parse_point(t_parsing p)
{
	t_dunit	u;

	u.x = parse_double(p);
	parse_char(p, ',');
	u.y = parse_double(p);
	parse_char(p, ',');
	u.z = parse_double(p);
	u.w = 1;
	return (u);
}
