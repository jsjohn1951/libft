/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 01:14:54 by wismith           #+#    #+#             */
/*   Updated: 2023/12/15 02:01:52 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binaryTree.h"

void		ft_update_heights(t_node *node);
t_node		*ft_init_node(const void *key, const void *value);
t_node		*ft_balance(t_node *node);
t_node		*ft_find_node(t_node *root, const void *key_val);

/*
* @brief attached pointers to the parents nodes
*/
void	ft_attach_parents(t_node *node, t_node *prev)
{
	if (node && node->data)
	{
		ft_attach_parents(node->node_left, node);
		node->node_parent = prev;
		ft_attach_parents(node->node_right, node);
	}
}

t_node	*ft_replace(t_node *old, t_node *new)
{
	new->node_left = old->node_left;
	new->node_right = old->node_right;
	new->node_parent = old->node_parent;
	free (old->data);
	free (old);
	old = new;
	return (old);
}

/*
*	@brief inserts new node into the tree or a branch of the tree
*		whose root node is passed as parameter.
*/
t_node	*ft_insert_node(t_node *root, t_node *node)
{
	if (!root)
	{
		root = node;
		return (root);
	}
	if (!ft_lexi_compare(root->data->key, node->data->key))
		root->node_left = ft_insert_node (root->node_left, node);
	else
		root->node_right = ft_insert_node (root->node_right, node);
	root = ft_balance(root);
	return (root);
}

/*
* @brief creates and inserts new node given the key/value pair provided
*	as argument.
*/
t_node	*ft_insert_new_node(t_node *root, const void *key, const void *value)
{
	t_node	*node;
	t_node	*res;

	if (!root)
		return (NULL);
	if (ft_find_node(root, key))
		return (root);
	node = ft_init_node(key, value);
	res = ft_insert_node(root, node);
	ft_attach_parents(res, NULL);
	ft_update_heights (root);
	return (res);
}
