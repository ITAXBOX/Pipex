/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:08:19 by aitawi            #+#    #+#             */
/*   Updated: 2025/05/21 19:48:21 by aitawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*answer;

	if (size != 0 && nmemb > 18446744073709551615UL / size)
		return (NULL);
	answer = malloc(nmemb * size);
	if (!answer)
		return (NULL);
	ft_memset(answer, 0, nmemb * size);
	return (answer);
}
