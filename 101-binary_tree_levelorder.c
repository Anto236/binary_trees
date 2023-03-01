#include "binary_trees.h"

/**
 * binary_tree_height - finds the height of a particular node
 * @tree: the node to find the height of
 * Return: ldepth if it is the largest node length or rdepth if not
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t ldepth;
	size_t rdepth;

	if (tree == NULL)
		return (0);

	ldepth = binary_tree_height(tree->left) + 1;
	rdepth = binary_tree_height(tree->right) + 1;

	if (ldepth > rdepth)
		return (ldepth);

	return (rdepth);
}

/**
 * print_level - prints nodes at the same level
 *
 * @tree: tree root
 * @level: level node
 * @func: pointer to a function
 * Return: no return
 */
void print_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level(tree->left, level - 1, func);
		print_level(tree->right, level - 1, func);
	}
}


/**
 * binary_tree_levelorder - prints data in level-order traversal
 *
 * @tree: tree root
 * @func: pointer to a function
 * Return: no return
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height;
	size_t i;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);

	for (i = 1; i <= height; i++)
		print_level(tree, i, func);
}
