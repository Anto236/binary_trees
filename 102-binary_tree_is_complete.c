#include "binary_trees.h"
/**
* binary_tree_size -  function that measures the size of a binary tree
*
* @tree: root
* Return: If tree is NULL, the function must return 0
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size, right_size;

	if (tree == NULL)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (left_size + right_size + 1);
}

/**
 * is_complete - Checks if a binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 * @idx: Index of the current node
 * @nodes: Total number of nodes in the tree
 *
 * Return: 1 if the binary tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, size_t idx, size_t nodes)
{
	if (tree == NULL)
		return (1);

	if (idx >= nodes)
		return (0);

	return (is_complete(tree->left, 2 * idx + 1, nodes) &&
		is_complete(tree->right, 2 * idx + 2, nodes));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the binary tree is complete, 0 otherwise.
 * If @tree is NULL, it returns 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t nodes, idx;

	if (tree == NULL)
		return (0);

	nodes = binary_tree_size(tree);
	idx = 0;

	return (is_complete(tree, idx, nodes));
}
