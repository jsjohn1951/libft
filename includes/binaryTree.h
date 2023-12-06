/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaryTree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:00:27 by wismith           #+#    #+#             */
/*   Updated: 2023/12/04 14:11:55 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARYTREE_H
# define BINARYTREE_H

# define ENDINSERT 0
# define INSERT 1

# include "./libft.h"

typedef struct s_pair
{
	void			*key;
	void			*value;
}	t_pair;

typedef struct s_node
{
	int				height;
	struct s_node	*node_left;
	struct s_node	*node_right;
	struct s_node	*node_parent;
	t_pair			*data;
}	t_node;

typedef struct s_tree
{
	t_node	*root;
	size_t	size;
}	t_tree;

typedef struct s_iterator
{
	t_node			*node;
	void			*data;
	void			*key;
	void			*value;
}	t_iterator;

//! Misc

int			ft_lexi_compare(const void *first, const void *second);
void		ft_print_tree(t_node *root, int space, int count);
t_node		*ft_tree_min(t_node *node);
t_node		*ft_tree_max(t_node *node);

void		ft_init_tree(t_tree *tree, const void *key, const void *value);
void		ft_insert(t_tree *tree, const void *key, const void *value);
void		ft_delete(t_tree *tree, const void *key);
t_node		*ft_find(t_tree *tree, const void *key);
void		ft_deallocate_tree(t_tree *tree);

t_iterator	*ft_set_iterator(t_iterator *iter, t_node *node);
t_iterator	*ft_incre_iterator(t_iterator *iter);
t_iterator	*ft_decre_iterator(t_iterator *iter);

#endif