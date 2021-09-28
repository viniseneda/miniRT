/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:40:18 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/23 18:27:53 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	b;

	i = 0;
	b = 0;
	if (ft_strlen(little) == 0)
		return ((char *)(big));
	while ((*(big + i) != '\0') && ((int)len != 0))
	{
		if (*(big + i) == *(little + b))
		{
			if (b + 1 == ft_strlen(little))
				return ((char *)(big + i - b));
			b++;
		}
		else
		{
			i = i - b;
			b = 0;
		}
		i++;
		if (i == len)
			break ;
	}
	return (NULL);
}
