/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 23:27:36 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/23 18:20:33 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	check_set(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (*(set + i) == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	int		b;
	int		e;
	char	*temp;

	size = ft_strlen(s1) - 1;
	b = 0;
	e = 0;
	while ((check_set(*(s1 + b), set) != 0) && (*(s1 + b) != '\0'))
		b++;
	while ((check_set(*(s1 + size - e), set) != 0) && (size - e >= 0))
		e++;
	if (b + e > size)
	{
		temp = (char *)malloc(1);
		if (temp == NULL)
			return (NULL);
		*temp = '\0';
		return (temp);
	}
	return (ft_substr(s1, b, size - b - e + 1));
}
