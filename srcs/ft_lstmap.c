/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:00:49 by wismith           #+#    #+#             */
/*   Updated: 2023/12/04 17:57:34 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*listy;
	t_list	*new;

	if (!f && !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		listy = ft_lstnew(f(lst->content));
		if (!listy)
		{
			ft_lstclear(&listy, del);
			return (NULL);
		}
		ft_lstadd_back(&new, listy);
		lst = lst->next;
	}
	return (new);
}
