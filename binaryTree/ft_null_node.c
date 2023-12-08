/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 00:25:16 by wismith           #+#    #+#             */
/*   Updated: 2023/12/08 23:57:15 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binaryTree.h"

void	ft_right_null_node(t_node *max)
{
	max->node_right = (t_node *)malloc(sizeof(t_node));
	max->node_right->data = NULL;
	max->node_right->node_left = NULL;
	max->node_right->node_right = NULL;
	max->node_right->node_parent = max;
}

void	ft_left_null_node(t_node *min)
{
	min->node_left = (t_node *)malloc(sizeof(t_node));
	min->node_left->data = NULL;
	min->node_left->node_left = NULL;
	min->node_left->node_right = NULL;
	min->node_left->node_parent = min;
}

void	ft_null_node(t_node *root, int flag)
{
	t_node	*min;
	t_node	*max;

	if (!root)
		return ;
	min = ft_tree_min(root);
	max = ft_tree_max(root);
	free (min->node_left);
	free (max->node_right);
	min->node_left = NULL;
	max->node_right = NULL;
	if (flag == ENDINSERT)
	{
		ft_left_null_node(min);
		ft_right_null_node(max);
	}
}
