/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:10:32 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/23 18:21:18 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*destiny;

	if ((dest == NULL && src == NULL) || n == 0)
		return (dest);
	if (src < dest)
	{
		source = (unsigned char *)src + n - 1;
		destiny = (unsigned char *)dest + n - 1;
		while (n--)
		{
			*destiny = *source;
			source--;
			destiny--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
