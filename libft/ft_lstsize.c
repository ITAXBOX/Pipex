/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 23:29:47 by aitawi            #+#    #+#             */
/*   Updated: 2025/05/21 23:40:27 by aitawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		answer;
	t_list	*temp;

	answer = 0;
	temp = lst;
	while (temp != NULL)
	{
		answer++;
		temp = temp -> next;
	}
	return (answer);
}
