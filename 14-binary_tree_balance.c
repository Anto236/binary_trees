#include "binary_trees.h"
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: balance factor of the tree, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}

/**
 * binary_tree_height - finds the height of a particular node
 * @tree: the node to find the height of
 * Return: ldepth if it is the largest node length or rdepth if not
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t ldepth;
	size_t rdepth;

	if (!tree)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left)
		ldepth = binary_tree_height(tree->left) + 1;
	else
		ldepth = 0;

	if (tree->right)
		rdepth = binary_tree_height(tree->right) + 1;
	else
		rdepth = 0;

	if (ldepth > rdepth)
		return (ldepth);
	else
		return (rdepth);
}
