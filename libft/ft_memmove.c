/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:53:24 by aitawi            #+#    #+#             */
/*   Updated: 2025/05/21 18:46:26 by aitawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*temp1;
	unsigned const char	*temp2;

	temp1 = (unsigned char *)dest;
	temp2 = (unsigned const char *)src;
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			temp1[i - 1] = temp2[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			temp1[i] = temp2[i];
			i++;
		}
	}
	return (dest);
}
