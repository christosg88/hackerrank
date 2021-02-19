/**
 * struct node
 * {
 *     int val;     // value
 *     node *left;  // left child
 *     node *right; // right child
 *     int ht;      // height of the node
 * };
 */

/**
 * Return the height of the binary tree, which is the max height of its two
 * children plus 1. The height of a leaf is considered 0 AND NOT 1.
 * @param  root a pointer to the root of the binary tree
 * @return      the height of the binary tree
 */
int height(node *root)
{
    if (root == nullptr)
        return -1;

    int ht = 0;

    if (root->left != nullptr && root->left->ht + 1 > ht)
        ht = 1 + root->left->ht;

    if (root->right != nullptr && root->right->ht + 1 > ht)
        ht = 1 + root->right->ht;

    return ht;
}

/**
 * Return the balance factor of the root.
 * @param  root a pointer to the root of the binary tree
 * @return      the balance factor of the root, which is the difference between
 *              the height of the left child and the right child
 */
int balance_factor(node *root)
{
    return height(root->left) - height(root->right);
}

/**
 * Performs a left rotation on the binary search tree, also updating their
 * heights.
 * @param  root a pointer to the root of the binary search tree
 * @return      a pointer to the new root of the binary search tree
 */
node *rotate_left(node *root)
{
    // perform the rotation
    node *tmp_node = root->right;
    root->right = tmp_node->left;
    tmp_node->left = root;

    // update the heights
    tmp_node->left->ht = height(tmp_node->left);
    tmp_node->ht = height(tmp_node);

    // return the new root
    return tmp_node;
}

/**
 * Performs a right rotation on the binary search tree, also updating their
 * heights.
 * @param  root a pointer to the root of the binary search tree
 * @return      a pointer to the new root of the binary search tree
 */
node *rotate_right(node *root)
{
    // perform the rotation
    node *tmp_node = root->left;
    root->left = tmp_node->right;
    tmp_node->right = root;

    // update the heights
    tmp_node->right->ht = height(tmp_node->right);
    tmp_node->ht = height(tmp_node);

    // return the new root
    return tmp_node;
}

/**
 * Inserts a new node in the self-balancing binary search tree, making sure the
 * tree stays balanced.
 * @param  root    a pointer to the root node
 * @param  new_val the value of the node to be inserted
 * @return         a pointer to the root of the binary search tree
 */
node *insert(node *root, int new_val)
{
    // if the root is nullptr we should insert the new node here
    if (root == nullptr)
    {
        node *new_node = new node;
        new_node->val = new_val;
        new_node->left = nullptr;
        new_node->right = nullptr;
        new_node->ht = 0;
        root = new_node;
    }
    // else we should try to insert it lower in the tree
    else
    {
        // if the new_val is bigger than the value of the root, insert at its
        // right child
        if (new_val > root->val)
        {
            root->right = insert(root->right, new_val);
            root->ht = height(root);    // recalculate its height
        }
        // else the new_val is smaller that the value of the root, so insert at
        // its left child
        else
        {
            root->left = insert(root->left, new_val);
            root->ht = height(root);    // recalculate its height
        }

        int bf1 = balance_factor(root);

        // left
        if (bf1 > 1)
        {
            int bf2 = balance_factor(root->left);
            // left -> right (rotate left)
            if (bf2 == -1)
            {
                root->left = rotate_left(root->left);
            }

            // left -> left (rotate right)
            root = rotate_right(root);
        }
        // right
        else if (bf1 < -1)
        {
            int bf2 = balance_factor(root->right);
            // right -> left (rotate right)
            if (bf2 == 1)
            {
                root->right = rotate_right(root->right);
            }

            // right -> right (rotate left)
            root = rotate_left(root);
        }
    }

    return root;
}
