/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_balance_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:11:39 by wismith           #+#    #+#             */
/*   Updated: 2023/12/03 17:04:40 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binaryTree.h"

void	ft_update_heights(t_node *node);
int		ft_difference(t_node *node);

t_node	*ft_left_rotate(t_node *node)
{
	t_node	*x;
	t_node	*y;

	x = node->node_right;
	y = x->node_left;
	x->node_left = node;
	node->node_right = y;
	ft_update_heights (node);
	ft_update_heights (x);
	return (x);
}

t_node	*ft_right_rotate(t_node *node)
{
	t_node	*x;
	t_node	*y;

	x = node->node_left;
	y = x->node_right;
	x->node_right = node;
	node->node_left = y;
	ft_update_heights (node);
	ft_update_heights (x);
	return (x);
}

t_node	*ft_left_right(t_node *node)
{
	node->node_left = ft_left_rotate(node->node_left);
	return (ft_right_rotate(node));
}

t_node	*ft_right_left(t_node *node)
{
	node->node_right = ft_right_rotate(node->node_right);
	return (ft_left_rotate(node));
}

t_node	*ft_balance(t_node *node)
{
	int	diff;

	ft_update_heights(node);
	diff = ft_difference(node);
	if (diff <= 1 && diff >= -1)
		return (node);
	if (diff > 1)
	{
		if (ft_difference(node->node_left) >= 0)
			node = ft_right_rotate(node);
		else
			node = ft_left_right(node);
	}
	else
	{
		if (ft_difference(node->node_right) <= 0)
			node = ft_left_rotate(node);
		else
			node = ft_right_left(node);
	}
	return (node);
}
