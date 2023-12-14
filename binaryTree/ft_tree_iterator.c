/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_iterator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:36:54 by wismith           #+#    #+#             */
/*   Updated: 2023/12/15 02:04:12 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binaryTree.h"

t_iterator	*ft_set_iterator(t_iterator *iter, t_node *node)
{
	if (!node)
		return (NULL);
	iter->node = node;
	iter->key = NULL;
	iter->value = NULL;
	iter->data = node->data;
	if (iter->node && node->data)
	{
		iter->key = node->data->key;
		iter->value = node->data->value;
	}
	return (iter);
}

t_iterator	*ft_incre_iterator(t_iterator *iter)
{
	t_node	*tmp;

	if (!iter)
		return (NULL);
	tmp = iter->node;
	if (iter->node->node_right)
		return (ft_set_iterator(iter,
				ft_tree_min(iter->node->node_right)));
	else if (iter->node->data)
	{
		while (ft_lexi_compare(tmp->node_parent->data->key,
				iter->node->data->key))
			tmp = tmp->node_parent;
	}
	return (ft_set_iterator(iter, tmp->node_parent));
}

t_iterator	*ft_decre_iterator(t_iterator *iter)
{
	t_node	*tmp;

	if (!iter)
		return (NULL);
	tmp = iter->node;
	if (iter->node->node_right)
		return (ft_set_iterator(iter,
				ft_tree_max(iter->node->node_right)));
	else if (iter->node->data)
	{
		while (ft_lexi_compare(iter->node->data->key,
				tmp->node_parent->data->key))
			tmp = tmp->node_parent;
	}
	return (ft_set_iterator(iter, tmp->node_parent));
}
