/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:23:21 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/23 18:21:30 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*st;

	i = 0;
	st = (unsigned char *)s;
	while (i < n)
	{
		if (*(st + i) == (unsigned char)c)
		{
			return (st + i);
		}
		i++;
	}
	return (NULL);
}
