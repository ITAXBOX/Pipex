/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:59:16 by aitawi            #+#    #+#             */
/*   Updated: 2025/05/21 19:43:30 by aitawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			n++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (n);
}

static char	*ft_create_and_copy(char const *str, char c)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	result = malloc(i * sizeof(char) + 1);
	if (!result)
		return (NULL);
	while (j < i)
	{
		result[j] = str[j];
		j++;
	}
	result[j] = '\0';
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**answer;

	if (!s)
		return (NULL);
	answer = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!answer)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			answer[j] = ft_create_and_copy(&s[i], c);
			j++;
		}
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	answer[j] = 0;
	return (answer);
}
