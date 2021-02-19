/**
 * struct node
 * {
 *     int data;
 *     node *left;
 *     node *right;
 * }
 */

/**
 * Inserts a new node in a binary search tree
 * @param  root  a pointer to the root of the binary search tree
 * @param  value the value of the data of the new node
 * @return       a pointer to the root of the binary search tree
 */
node *insert(node *root, int value)
{
    // create the new node
    node *new_node = new node;
    new_node->data = value;
    new_node->left = nullptr;
    new_node->right = nullptr;

    // check for empty binary search tree
    if (root == nullptr)
        return new_node;

    node *traverse_node = root;
    while (true)
    {
        // if value is smaller than the current node's value
        if (value < traverse_node->data)
        {
            // if there is already a node at the left, go there
            if (traverse_node->left != nullptr)
            {
                traverse_node = traverse_node->left;
            }
            // else add the new node at the left of the current node
            else
            {
                traverse_node->left = new_node;
                return root;
            }
        }
        // else the value is greater or equal to the current node's value
        else
        {
            // if there is already a node at the right, go there
            if (traverse_node->right != nullptr)
            {
                traverse_node = traverse_node->right;
            }
            // else add the new node at the right of the current node
            else
            {
                traverse_node->right = new_node;
                return root;
            }
        }
    }
}
