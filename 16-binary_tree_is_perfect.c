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
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: a pointer to the node to measure the depth
 * Return: the depth of the tree, 0 if @tree == NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t count;

	if (tree == NULL || tree->parent == NULL)
		return (0);

	count = binary_tree_depth(tree->parent);
	count++;
	return (count);
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
* binary_tree_is_perfect - checks if a binary tree is perfect
*
* @tree: the root
* Return: If tree is NULL, your function must return 0
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_is_full(tree) && binary_tree_balance(tree) == 0)
	{
		int ldepth = binary_tree_depth(tree->left);
		int rdepth = binary_tree_depth(tree->right);

		if (ldepth == rdepth)
			return (1);
	}
	return (0);
}
