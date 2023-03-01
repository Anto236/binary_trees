#include "binary_trees.h"
/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, NULL, NULL));
}

/**
 * is_bst_helper - Recursively checks if a binary tree is a valid BST.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Pointer to the minimum value that the
 * current node's value must be greater than.
 * @max: Pointer to the maximum value that the
 * current node's value must be less than.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int is_bst_helper(const binary_tree_t *tree, const int *min, const int *max)
{
	if (tree == NULL)
		return (1);

	if (min != NULL && tree->n <= *min)
		return (0);

	if (max != NULL && tree->n >= *max)
		return (0);

	return (is_bst_helper(tree->left, min, &tree->n) &&
		is_bst_helper(tree->right, &tree->n, max));
}
