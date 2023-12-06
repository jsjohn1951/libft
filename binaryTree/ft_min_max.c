/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:37:25 by wismith           #+#    #+#             */
/*   Updated: 2023/12/03 23:59:11 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binaryTree.h"

t_node	*ft_tree_min(t_node *node)
{
	if (node && node->node_left && node->node_left->data)
		node = ft_tree_min (node->node_left);
	return (node);
}

t_node	*ft_tree_max(t_node *node)
{
	if (node && node->node_right && node->node_right->data)
		node = ft_tree_max (node->node_right);
	return (node);
}
