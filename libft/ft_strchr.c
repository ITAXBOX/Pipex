/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:25:54 by aitawi            #+#    #+#             */
/*   Updated: 2025/05/21 16:41:28 by aitawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	temp;

	if (!s)
		return (NULL);
	i = 0;
	temp = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == temp)
			return ((char *)(s + i));
		i++;
	}
	if (temp == '\0')
		return ((char *)(s + i));
	return (NULL);
}
