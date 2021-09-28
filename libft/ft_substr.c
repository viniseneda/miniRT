/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 08:32:46 by vvarussa          #+#    #+#             */
/*   Updated: 2021/02/17 08:42:37 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*temp;
	unsigned int	i;
	unsigned int	a;

	if (len > ft_strlen(s))
		temp = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		temp = malloc(sizeof(char) * (len + 1));
	if (temp == NULL)
		return (NULL);
	*temp = '\0';
	i = start;
	a = 0;
	if (start > ft_strlen(s))
		return (temp);
	if (temp == NULL)
		return (NULL);
	while (a < len)
	{
		*(temp + a) = *(s + i);
		i++;
		a++;
	}
	*(temp + a) = '\0';
	return (temp);
}
