/**
 * struct node
 * {
 *     int data;
 *     node *left;
 *     node *right;
 * }
 */

/**
 * Returns the height of the binary tree.
 * @param  root a pointer to the root of the binary tree
 * @return      the height of the binary tree
 */
int height(node *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + std::max(height(root->left), height(root->right));
}
