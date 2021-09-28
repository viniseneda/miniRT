/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 22:56:57 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/23 18:17:29 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*temp;
	unsigned int	size_a;
	unsigned int	size_b;

	size_a = ft_strlen(s1);
	size_b = ft_strlen(s2);
	temp = (char *)malloc(size_a + size_b + 1);
	if (temp == NULL)
		return (NULL);
	ft_strlcpy(temp, s1, size_a + 1);
	temp = temp + size_a;
	ft_strlcpy(temp, s2, size_b + 1);
	return (temp - size_a);
}
