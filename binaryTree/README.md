# ```> binaryTree```
Those who are familiar with the ```stl Map in c++``` and how its iterators can be used to traverse the binary tree
will understand why I've implemented a set of usable functions to create something similar in ```c```.
Binary Trees allow us to sort data and store them in a tree like linked list with each node having a pointer to
its left child, right child, and parent nodes.
Because I wrote it in c, the functionality will never be exactly the same as the original ```Stl Map in c++```
therefore my recommended use is to always keep the key value as a ```char *```. Both the ```key``` and ```value```
were declared as ```void *``` to give the binary tree key / value pair a more generic functionality. A downside to this
is that the user needs to typecast the key or value to have access to the data pointed to.
Neither key, nor value, is reallocated when initializing a node, so it is expected that the allocation, and freeing
be handled by the user.
---
### Initializing a tree:
```c
int main(void)
{
    // Declare a tree structure
    t_tree	tree;
    
    // initializes the tree
    ft_init_tree(&tree, "test", "A for Alpha");

    // takes an address of a tree and creates and inserts new node
    ft_insert(&tree, "srcs", "B for Bravo");
    ft_insert(&tree, "objects", "C for Chalie");
    ft_insert(&tree, "main.c", "D for Delta");

    // prints a 2d tree
    ft_print_tree(tree.root, 0, 10);

    // Deallocates the nodes and the key / value pair contained within.
    ft_deallocate_tree(&tree);
    return (0);
}
```

### Output:
```
          test

srcs

          objects

                    main.c
```
---
### Iterators
In order to make it more convenient to traverse the binary tree I have implemented a c version of iterators with
helper functions that allow for the iterators to move to the next node. The iterator structure contains pointers to
the node it is currently on, the key and value within the key / value pair contained within the node. This is done in
order that if the user allocated the key and/or value on the heap, they can easily traverse the tree and free each heap allocated 
key or value.
### Initializing and using iterator:
```c
t_iterator	iterator;

ft_set_iterator(&iterator, ft_tree_min(tree.root));

for (; iterator.node->data;)
{
    printf("%s\n", (char *) iterator.key);
	ft_incre_iterator(&iterator);
}
```
---
### list of functions prototypes
| Misc |
| :-- |
| int		ft_lexi_compare ( const void *first, const void *second ); |
| void		ft_print_tree ( t_node *root, int space, int count ); |
| t_node	*ft_tree_min ( t_node *node ); |
| t_node	*ft_tree_max ( t_node *node ); |

| list of libft binary tree associated functions |
| :-- |
| void		ft_init_tree ( t_tree *tree, const void *key, const void *value ); |
| void		ft_insert ( t_tree *tree, const void *key, const void *value ); |
| void		ft_delete ( t_tree *tree, const void *key ); |
| t_node	*ft_find ( t_tree *tree, const void *key ); |
| void		ft_deallocate_tree ( t_tree *tree ); |

| list of libft binary tree iterator associated functions |
| :-- |
| t_iterator	*ft_set_iterator ( t_iterator *iter, t_node *node ); |
| t_iterator	*ft_incre_iterator ( t_iterator *iter ); |
| t_iterator	*ft_decre_iterator ( t_iterator *iter ); |