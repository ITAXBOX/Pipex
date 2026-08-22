/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:20:48 by aitawi            #+#    #+#             */
/*   Updated: 2025/05/21 17:38:10 by aitawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;
	char	*answer;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	answer = malloc(s1_len + s2_len + 1);
	if (!answer)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		answer[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		answer[i++] = s2[j++];
	answer[i] = '\0';
	return (answer);
}
