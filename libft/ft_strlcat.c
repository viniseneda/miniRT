/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 21:06:22 by vvarussa          #+#    #+#             */
/*   Updated: 2021/02/16 08:16:20 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			len_a;
	size_t			len_b;

	len_a = ft_strlen(src);
	len_b = ft_strlen(dst);
	if (size > len_b + 1)
	{
		i = 0;
		while (i + len_b < size - 1 && *(src + i) != '\0')
		{
			*(dst + len_b + i) = *(src + i);
			i++;
		}
		*(dst + len_b + i) = '\0';
	}
	if ((len_a + size > len_a + len_b) | ((int)size < 0))
		return (len_a + len_b);
	return (len_a + size);
}
