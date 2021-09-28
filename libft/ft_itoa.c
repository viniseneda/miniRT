/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 22:35:57 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/23 18:20:02 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	str_gen(int *size, int temp, char *number)
{
	while (temp < size[11])
	{
		if (size[size[11] - temp - 1] < 0)
			*(number + temp) = '-';
		else
			*(number + temp) = size[size[11] - temp - 1] + '0';
		temp++;
	}
	*(number + temp) = '\0';
}

static void	num_iterator(int *size, long int temp)
{
	if (temp == 0)
	{
		size[0] = 0;
		size[11]++;
	}
	while ((temp % 10 != 0) || (temp / 10 != 0))
	{
		size[size[11]] = temp % 10;
		temp = temp / 10;
		size[11]++;
	}
}

char	*ft_itoa(int n)
{
	int			sign;
	long int	nb;
	int			size[12];
	char		*number;

	sign = 0;
	nb = n;
	if (n < 0)
	{
		sign = 1;
		nb = nb * -1;
	}
	size[11] = 0;
	num_iterator(size, nb);
	if (sign == 1)
	{
		size[size[11]] = -1;
		size[11]++;
	}
	number = (char *)malloc(size[11] + sign + 1);
	if (number == NULL)
		return (NULL);
	str_gen(size, 0, number);
	return (number);
}
