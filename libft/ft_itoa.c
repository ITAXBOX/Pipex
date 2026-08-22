/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:12:55 by aitawi            #+#    #+#             */
/*   Updated: 2025/05/21 20:54:21 by aitawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
	long	l;
	int		answer;

	l = n;
	answer = 0;
	if (n == 0)
		return (1);
	if (l < 0)
	{
		answer = 1;
		l = -l;
	}
	while (l != 0)
	{
		l /= 10;
		answer++;
	}
	return (answer);
}

char	*ft_itoa(int n)
{
	char	*answer;
	int		digits_num;
	long	l;
	int		sign;

	sign = 0;
	digits_num = ft_count_digits(n);
	answer = malloc(sizeof(char) * (digits_num + 1));
	if (!answer)
		return (NULL);
	answer[digits_num--] = '\0';
	l = n;
	if (n < 0)
	{
		l = -l;
		sign = 1;
	}
	while (digits_num >= sign)
	{
		answer[digits_num--] = (l % 10) + '0';
		l /= 10;
	}
	if (n < 0)
		answer[digits_num] = '-';
	return (answer);
}
