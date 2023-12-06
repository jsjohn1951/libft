/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 01:02:08 by wismith           #+#    #+#             */
/*   Updated: 2023/12/03 23:43:16 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binaryTree.h"

void	ft_print_tree(t_node *root, int space, int count)
{
	int	i;

	i = count;
	if (!root || !root->data)
		return ;
	space += count;
	ft_print_tree (root->node_right, space, count);
	ft_putstr_fd("\n", 1);
	while (i++ < space)
		ft_putstr_fd(" ", 1);
	ft_putstr_fd ((char *) root->data->key, 1);
	ft_putstr_fd("\n", 1);
	ft_print_tree (root->node_left, space, count);
}
