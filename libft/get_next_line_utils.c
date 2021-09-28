/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:30:54 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/23 18:26:45 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*copy(char *return_string, char *src)
{
	while (*src)
	{
		*return_string = *src;
		src++;
		return_string++;
	}
	return (return_string);
}
