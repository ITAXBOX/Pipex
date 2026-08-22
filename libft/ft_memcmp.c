/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:53:39 by aitawi            #+#    #+#             */
/*   Updated: 2025/05/21 17:19:38 by aitawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*temp1;
	unsigned const char	*temp2;

	i = 0;
	temp1 = (const unsigned char *)s1;
	temp2 = (const unsigned char *)s2;
	while (i < n && temp1[i] == temp2[i])
		i++;
	if (i == n)
		return (0);
	return (temp1[i] - temp2[i]);
}
