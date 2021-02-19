/**
 * struct node
 * {
 *     int data;
 *     node *left;
 *     node *right;
 * }
 */

/**
 * Prints the values of the binary tree in in-order traversal.
 * @param root a pointer to the root of the binary tree
 */
void Inorder(node *root)
{
    if (root->left != nullptr)
        Inorder(root->left);

    std::cout << root->data << ' ';

    if (root->right != nullptr)
        Inorder(root->right);
}
