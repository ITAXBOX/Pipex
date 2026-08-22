/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:10:56 by aitawi            #+#    #+#             */
/*   Updated: 2025/05/21 17:19:49 by aitawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	n;
	size_t	i;
	char	*answer;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	answer = malloc(sizeof(char) * (n + 1));
	if (!answer)
		return (NULL);
	i = 0;
	while (i < n)
	{
		answer[i] = s[i];
		i++;
	}
	answer[i] = '\0';
	return (answer);
}
