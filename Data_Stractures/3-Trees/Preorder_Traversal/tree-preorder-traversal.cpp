/**
 * struct node
 * {
 *     int data;
 *     node *left;
 *     node *right;
 * }
 */

/**
 * Prints the values of the binary tree in preorder traversal.
 * @param root a pointer to the root of the binary tree
 */
void Preorder(node *root)
{
    std::cout << root->data << ' ';

    if (root->left != NULL)
        Preorder(root->left);
    if (root->right != NULL)
        Preorder(root->right);
}
