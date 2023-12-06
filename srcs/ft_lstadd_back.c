/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:09:39 by wismith           #+#    #+#             */
/*   Updated: 2023/12/04 17:56:50 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*start;

	start = *lst;
	if (!lst)
		return ;
	if (!*lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else if (lst && *lst && new)
	{
		while (start->next)
			start = start->next;
		start->next = new;
	}
}
