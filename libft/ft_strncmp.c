/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:18:28 by vvarussa          #+#    #+#             */
/*   Updated: 2021/02/16 12:24:43 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n > ft_strlen(s1) && ft_strlen(s1) != 0)
		n = ft_strlen(s1) + 1;
	return (ft_memcmp(s1, s2, n));
}
