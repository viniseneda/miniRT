/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:56:41 by vvarussa          #+#    #+#             */
/*   Updated: 2021/02/15 20:56:53 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	int				len;

	i = 0;
	len = ft_strlen(src);
	while (i < size)
	{
		*(dst + i) = *(src + i);
		if (*(src + i) == '\0')
		{
			return (len);
		}
		i++;
	}
	if (size != 0)
		*(dst + i - 1) = '\0';
	return (len);
}
