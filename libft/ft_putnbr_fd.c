/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:05:22 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/23 18:16:56 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <unistd.h>

static void	str_gen(int *size, int temp, int fd)
{
	char	t;

	while (temp < size[11])
	{
		t = size[size[11] - temp - 1] + '0';
		if (size[size[11] - temp - 1] < 0)
			write(fd, "-", 1);
		else
			write(fd, &t, 1);
		temp++;
	}
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

void	ft_putnbr_fd(int n, int fd)
{
	int			sign;
	long int	nb;
	int			size[12];

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
	str_gen(size, 0, fd);
	return ;
}
