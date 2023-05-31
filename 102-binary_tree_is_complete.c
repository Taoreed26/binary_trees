#include "binary_trees.h"

/**
 * node_is_complete - checks for completion
 * @node: evaluates
 * Return: successful returns "1", unsuccessful returns "0" just like "high and low", "on & Off"
 */
int node_is_complete(const binary_tree_t *node)
{
	if ((node && node->left && node->right))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * binary_tree_height - gives the information of the height.
 *@tree: pointing to the measured root.
 * Return: fuction  returns "0" if tree is null.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left = 0, right = 0;

		if (tree->right)
			right = 1 + binary_tree_height(tree->right);
		if (tree->left)
			left = 1 + binary_tree_height(tree->left);
		if (left > right)
			return (left);
		return (right);
	}
	return (0);
}
/**
 * check_complete_level - prints node at the required level
 * @tree: pointing to the measured root
 * @level: points to a function.
 * Return: returns true when completed
 */
int check_complete_level(const binary_tree_t *tree, int level)
{
	if (tree)
	{
		int left_v = 0, right_v = 0;

		if (level == 1)
			return (node_is_complete(tree));
		left_v = check_complete_level(tree->left, level - 1);
		right_v = check_complete_level(tree->right, level - 1);
		return (left_v || right_v);
	}
	return (0);
}
/**
 * check_left_level - check level that contains left-node
 * @tree: it points to the root node
 * @flag: flags if left is present
 * @level: points to a function.
 * Return: returns true for completion
 */
int check_left_level(const binary_tree_t *tree, int level, int *flag)
{

	if (tree)
	{
		if (level == 1)
		{
			if (*flag && tree->right == NULL)
				*flag = 0;
			if (*flag == 1 && tree->right == NULL && tree->left == NULL)
				return (1);
			if (tree->left == NULL && *flag)
				return (0);
			if (*flag == 0 && (tree->right || tree->left))
				return (0);
			return (1);
		}
		else
		{
			int left_v = 0, right_v = 0;

			left_v = check_left_level(tree->left, level - 1, flag);
			right_v = check_left_level(tree->right, level - 1, flag);
			return (left_v && right_v);
		}
	}
	return (0);
}
/**
 * binary_tree_is_complete: it checks whether binary tree is complete
 * @tree:evaluates completed task
 * Return: successful returns "1", unsuccessful returns "0" just like "high and low", "on & Off"
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int aux = 1, level = 1, t;

	if (tree)
	{
		t = binary_tree_height(tree);
		while (level < t  && aux)
		{
			aux = check_complete_level(tree, level);
			level++;
		}
		if (t == 0)
			return (1);
		if (aux)
			return (check_left_level(tree, t, &aux));
	}
	else
	{
		return (0);
	}
	return (0);
}
