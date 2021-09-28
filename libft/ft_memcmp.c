/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:09:48 by vvarussa          #+#    #+#             */
/*   Updated: 2021/02/15 18:30:59 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	int					sub;
	const unsigned char	*n1;
	const unsigned char	*n2;

	i = 0;
	n1 = s1;
	n2 = s2;
	sub = 0;
	while (i < n)
	{
		sub = *(n1 + i) - *(n2 + i);
		if (sub != 0)
		{
			return (sub);
		}
		i++;
	}
	return (0);
}
