/**
 * struct node
 * {
 *     int data;
 *     node *left;
 *     node *right;
 * }
 */

/**
 * Prints the binary in level order, that is from top to bottom, left to right
 * @param root a pointer to the root of the binary tree
 */
void LevelOrder(node *root)
{
    std::deque<node *> nodes;

    nodes.push_back(root);
    while (!nodes.empty())
    {
        node *tmp_node = nodes.front();
        nodes.pop_front();

        std::cout << tmp_node->data << ' ';

        if (tmp_node->left != nullptr)
            nodes.push_back(tmp_node->left);
        if (tmp_node->right != nullptr)
            nodes.push_back(tmp_node->right);
    }

    std::cout << '\n';
}
