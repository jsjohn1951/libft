/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:47:25 by wismith           #+#    #+#             */
/*   Updated: 2023/12/04 00:01:13 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binaryTree.h"

/*
* @brief frees the tree which includes the node passed as parameter 
*	and all associated child branches
*/
void	ft_destroy_tree(t_node *root)
{
	if (!root)
		return ;
	ft_destroy_tree(root->node_left);
	ft_destroy_tree(root->node_right);
	if (root->data)
		free (root->data);
	free (root);
}
