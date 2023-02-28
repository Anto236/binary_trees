#include "binary_trees.h"
/**
* binary_tree_is_leaf - function that checks if a node is a leaf
*
* @node: pointer to the node to check
* Return: 1 if node is root, o if not or node is NULL
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->left == NULL && node->right == NULL)
		return (1);

	return (0);
}
/**
* binary_tree_is_full - checks if a binary tree is full
*
* @tree: a pointer to the root node of the tree to check
* Return: 1 if it is full, 0 if not or if tree == NULL
*/
int binary_tree_is_full(const binary_tree_t *tree)
{

	if (tree->left && tree->right)
		return (binary_tree_is_leaf(tree->left) && binary_tree_is_leaf(tree->right));

	return (0);
}
