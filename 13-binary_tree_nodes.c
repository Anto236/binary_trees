#include "binary_trees.h"
/**
* binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
*
* @tree: pointer to the root to check
* Return: 1 if node is root, o if not or node is NULL
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	leaves += binary_tree_nodes(tree->left);
	leaves += binary_tree_nodes(tree->right);

	return (leaves + 1);
}
