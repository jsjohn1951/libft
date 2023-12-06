/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:06:02 by wismith           #+#    #+#             */
/*   Updated: 2023/12/03 17:04:40 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binaryTree.h"

/*
* @brief initializes a new node for the binary tree
*/
t_node	*ft_init_node(const void *key, const void *value)
{
	t_node	*root;

	root = (t_node *)malloc(sizeof(t_node));
	if (!root)
		return (NULL);
	root->data = (t_pair *) malloc(sizeof(t_pair));
	root->data->key = (void *) key;
	root->data->value = (void *) value;
	root->node_left = NULL;
	root->node_right = NULL;
	root->node_parent = NULL;
	return (root);
}
