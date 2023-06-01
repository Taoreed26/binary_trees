#include "binary_trees.h"
/**
 * bst_search: finds the node
 * @tree: this is the root
 * @value: the node to find
 * Return: return high low
 */
bst_t *bst_search(const bst_t *tree, int value)
{

	if (tree == NULL)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *)tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
	return (NULL);
}
