/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 22:05:00 by vvarussa          #+#    #+#             */
/*   Updated: 2021/02/18 22:24:52 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*temp;
	unsigned int	i;

	temp = (char *)malloc(ft_strlen(s) + 1);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		*(temp + i) = (*f)(i, *(s + i));
		i++;
	}
	*(temp + i) = '\0';
	return (temp);
}
