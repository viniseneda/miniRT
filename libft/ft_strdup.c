/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:58:13 by vvarussa          #+#    #+#             */
/*   Updated: 2021/02/16 19:02:49 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*temp;

	temp = malloc(ft_strlen(s) + 1);
	if (temp == NULL)
		return (NULL);
	ft_strlcpy(temp, s, ft_strlen(s) + 1);
	return (temp);
}
