/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:11:37 by wismith           #+#    #+#             */
/*   Updated: 2023/12/15 01:01:06 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binaryTree.h"

/*
* @brief finds a node within the binary tree using the key value.
*/
t_node	*ft_find_node(t_node *root, const void *key_val)
{
	unsigned char	*key;
	t_node			*left;

	key = (unsigned char *) key_val;
	if (!root || !root->data)
		return (NULL);
	if (!ft_lexi_compare(root->data->key, key)
		&& !ft_lexi_compare(key, root->data->key))
		return (root);
	left = ft_find_node(root->node_left, key);
	if (left)
		return (left);
	return (ft_find_node(root->node_right, key));
}
