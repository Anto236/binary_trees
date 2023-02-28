#include "binary_trees.h"
/**
* binary_tree_is_full - checks if a binary tree is full
*
* @tree: a pointer to the root node of the tree to check
* Return: 1 if it is full, 0 if not or if tree == NULL
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	return (0);
}

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

/**
* binary_tree_is_perfect - function that checks if a binary tree is perfect
*
* @tree: the root
* Return: If tree is NULL, your function must return 0
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_nodes, right_nodes;

	if (tree == NULL)
		return (0);

	if ((tree->left == NULL) && (tree->right == NULL))
		return (1);

	if (binary_tree_is_full(tree) == 0)
		return (0);

	left_nodes = binary_tree_nodes(tree->left);
	right_nodes = binary_tree_nodes(tree->right);

	if (left_nodes == right_nodes)
		return (1);
	else
		return (0);
}
