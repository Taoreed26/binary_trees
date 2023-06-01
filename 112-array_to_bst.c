#include "binary_trees.h"

/**
 * array_to_bst - builds the binary search.
 * @array: this is a pointer
 * @size: gives information of the elements.
 * Return: returns null
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree;
	size_t index;

	if (array == NULL)
		return (NULL);
	tree = NULL;
	for (index = 0; index < size; index++)
	{
		bst_insert(&tree, array[index]);
	}
	return (tree);
}
