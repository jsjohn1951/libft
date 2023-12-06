/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:10:53 by wismith           #+#    #+#             */
/*   Updated: 2023/12/04 02:14:03 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binaryTree.h"

t_node		*ft_balance(t_node *node);

t_node	*ft_deallocate(t_node *node)
{
	free (node->data);
	free (node);
	return (NULL);
}

t_node	*ft_destroy_replace(t_node *node)
{
	t_node	*new_node;

	new_node = NULL;
	if (!node->node_left && node->node_right)
		new_node = node->node_right;
	else if (node->node_left && !node->node_right)
		new_node = node->node_left;
	ft_deallocate(node);
	return (new_node);
}

t_node	*ft_find_delete_node(t_node *node, const void *key)
{
	t_node	*temp;

	if (!node)
		return (node);
	if (ft_lexi_compare(key, node->data->key))
		node->node_left = ft_find_delete_node(node->node_left, key);
	else if (ft_lexi_compare(node->data->key, key))
		node->node_right = ft_find_delete_node(node->node_right, key);
	else
	{
		if (!node->node_left || !node->node_right)
			return (ft_destroy_replace(node));
		temp = ft_tree_min(node->node_right);
		node->data->key = temp->data->key;
		node->data->value = temp->data->value;
		node->node_right = ft_find_delete_node(node->node_right, key);
	}
	node = ft_balance(node);
	return (node);
}

t_node	*ft_delete_node(t_node *root, const void *key)
{
	return (ft_find_delete_node(root, key));
}
