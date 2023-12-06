/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:17:32 by wismith           #+#    #+#             */
/*   Updated: 2023/12/04 02:14:41 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binaryTree.h"

void		ft_null_node(t_node *root, int flag);
t_node		*ft_init_node(const void *key, const void *value);
t_node		*ft_insert_new_node(t_node *root,
				const void *key, const void *value);
void		ft_destroy_tree(t_node *root);
t_node		*ft_find_node(t_node *root, const void *key_val);
t_node		*ft_delete_node(t_node *root, const void *key);

/*
* @brief takes the address of the tree structure
*	and the key value for the search parameter as argument.
*	Returns a pointer to the t_node of the found element or NULL if
*	not found.
*/
t_node	*ft_find(t_tree *tree, const void *key)
{
	return (ft_find_node(tree->root, key));
}

/*
* @brief takes the address of the tree structure
*	deallocates the null nodes and then proceeds to
*	deallocate each node and the data pairs within.
*/
void	ft_deallocate_tree(t_tree *tree)
{
	ft_null_node(tree->root, INSERT);
	ft_destroy_tree(tree->root);
}

/*
* @brief takes the address of the tree structure
*	and the key value of the node to be removed as arguments.
*	If the node exists with same key value, size is decreased by 1,
*	and the node is removed and deallocated allong with it's data pair.
*/
void	ft_delete(t_tree *tree, const void *key)
{
	if (tree->size && ft_find_node(tree->root, key))
	{
		tree->size--;
		tree->root = ft_delete_node(tree->root, key);
	}
}

/*
* @brief takes the address of the tree structure,
*	the key and the value as arguments.
*	If a node with same key value is not found, 
*	increases size by 1 and allocates and inserts a new node containing
*	a newly allocated data pair,
*	otherwise just updates the value contained within the data.
*/
void	ft_insert(t_tree *tree, const void *key, const void *value)
{
	ft_null_node(tree->root, INSERT);
	if (!ft_find_node(tree->root, key))
		tree->size++;
	tree->root = ft_insert_new_node(tree->root, key, value);
	ft_null_node(tree->root, ENDINSERT);
}

/*
* @brief takes the address of the tree structure,
*	the key and the value as arguments.
*	Allocates a new node and data pair contained within
*	and sets the root of the tree to the new node.
*	Sets size to 1.
*/
void	ft_init_tree(t_tree *tree, const void *key, const void *value)
{
	tree->size = 1;
	tree->root = ft_init_node(key, value);
	ft_null_node(tree->root, ENDINSERT);
}
