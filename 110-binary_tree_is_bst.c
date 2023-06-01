#include "binary_trees.h"
/**
 * find_node: it finds the tree node
 * @root:points to the root ready for access and evaluation
 * @node: finds node
 * Return: returns high if it is in existence and Lowwhen it's not existing hence 1&0
 */
int find_node(binary_tree_t *root, binary_tree_t *node)
{

	if (root == NULL)
		return (0);
	if (node == root)
		return (1);
	if (node->n < root->n)
		return (find_node(root->left, node));
	if (node->n > root->n)
		return (find_node(root->right, node));
	return (0);
}
/**
 * croos_tree - checks the presence of node and ensure it is correct
 * @root: points to the node on the tree
 * @node: node ready for evaluation
 * Return:returns high and low and follow the command instructions after it been checked by functions
 */
int croos_tree(binary_tree_t *root, binary_tree_t *node)
{
	if (root && node)
	{
		int aux = 0;

		aux = find_node(root, node);
		if (node->left)
			aux &= croos_tree(root, node->left);
		if (node->right)
			aux &= croos_tree(root, node->right);
		return (aux);
	}
	return (0);
}
/**
 * binary_tree_is_bst -checks the tree correctly
 * @tree: scrutinizes the tree
 * Return: returns high and low
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (croos_tree((binary_tree_t *)tree, (binary_tree_t *)tree));
}
