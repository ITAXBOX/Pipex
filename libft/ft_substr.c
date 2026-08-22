/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:04:27 by aitawi            #+#    #+#             */
/*   Updated: 2025/05/21 17:20:14 by aitawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*answer;
	size_t	i;
	size_t	j;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	answer = malloc(len + 1);
	if (!answer)
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[i] != '\0')
	{
		answer[j] = s[i];
		i++;
		j++;
	}
	answer[j] = '\0';
	return (answer);
}
