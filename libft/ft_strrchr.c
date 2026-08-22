/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:31:22 by aitawi            #+#    #+#             */
/*   Updated: 2025/05/21 17:20:11 by aitawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	temp;

	if (!s)
		return (NULL);
	temp = (char)c;
	i = 0;
	while (s[i])
		i++;
	while (i > 0)
	{
		if (s[i] == temp)
			return ((char *)(s + i));
		i--;
	}
	if (s[i] == temp)
		return ((char *)(s + i));
	return (NULL);
}
