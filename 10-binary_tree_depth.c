#include "binary_trees.h"

/**
 * binary_tree_depth - gives the idea of what the depth of a node in a binary tree is.
 *@tree: points to the node togive the idea of the depth.
 * Return: if tree == null, 0 returns as function
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);
	else
		return (1 + binary_tree_depth(tree->parent));
}
