/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:50:27 by aitawi            #+#    #+#             */
/*   Updated: 2025/05/21 16:38:52 by aitawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	if (!s)
		return (NULL);
	i = 0;
	temp = (unsigned char *) s;
	while (i < n)
	{
		temp[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
