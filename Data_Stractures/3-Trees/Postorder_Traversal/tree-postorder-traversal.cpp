/**
 * struct node
 * {
 *     int data;
 *     node *left;
 *     node *right;
 * }
 */

/**
 * Prints the values of the binary tree in postorder traversal.
 * @param root a pointer to the root of the binary tree
 */
void Postorder(node *root)
{
    if (root->left != NULL)
        Postorder(root->left);
    if (root->right != NULL)
        Postorder(root->right);

    std::cout << root->data << ' ';
}
