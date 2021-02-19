/**
 * struct node
 * {
 *     int data;
 *     node *left;
 *     node *right;
 * }
 */

/**
 * Prints all the nodes of the binary tree that can be seen from the top view.
 * @param root a pointer to the root of the binary tree
 */
void top_view(node *root)
{
    std::deque<int> top_view_nodes;

    // start  from the root and always move to the left adding each data at the
    // front of the queue
    node *traverse_node = root->left;
    while (traverse_node != NULL)
    {
        top_view_nodes.push_front(traverse_node->data);
        traverse_node = traverse_node->left;
    }

    // add the root node data
    top_view_nodes.push_back(root->data);

    // start  from the root and always move to the right adding each data at the
    // back of the queue
    traverse_node = root->right;
    while (traverse_node != NULL)
    {
        top_view_nodes.push_back(traverse_node->data);
        traverse_node = traverse_node->right;
    }

    // print all the nodes as seen from the top view
    for (int i = 0; i < top_view_nodes.size(); ++i)
        std::cout << top_view_nodes[i] << ' ';
    std::cout << '\n';
}
