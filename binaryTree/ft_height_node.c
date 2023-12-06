/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_height_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:14:50 by wismith           #+#    #+#             */
/*   Updated: 2023/12/03 17:04:40 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binaryTree.h"

int	ft_node_height(t_node *root, int level)
{
	int	size1;
	int	size2;

	size1 = 0;
	size2 = 0;
	if (root)
	{
		size1 = ft_node_height (root->node_left, level + 1);
		size2 = ft_node_height (root->node_right, level + 1);
		if (size1 >= size2)
			return (size1);
		return (size2);
	}
	return (level);
}

int	ft_get_height(t_node *node)
{
	if (!node)
		return (0);
	return (node->height);
}

int	ft_difference(t_node *node)
{
	if (!node)
		return (0);
	return (ft_get_height(node->node_left)
		- ft_get_height(node->node_right));
}

void	ft_update_heights(t_node *node)
{
	if (!node)
		return ;
	node->height = ft_node_height(node, 0);
	ft_update_heights (node->node_left);
	ft_update_heights (node->node_right);
}
