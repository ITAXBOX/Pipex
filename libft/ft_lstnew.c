/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:07:05 by aitawi            #+#    #+#             */
/*   Updated: 2025/05/21 23:40:33 by aitawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*answer;

	answer = malloc(sizeof(t_list));
	if (!answer)
		return (NULL);
	answer -> content = content;
	answer -> next = NULL;
	return (answer);
}
