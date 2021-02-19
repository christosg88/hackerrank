/**
 * struct node
 * {
 *     int data;
 *     node *left;
 *     node *right;
 * }
 */

node *lca(node *root, int v1, int v2)
{
    int min, max;

    if (v1 < v2)
    {
        min = v1;
        max = v2;
    }
    else
    {
        min = v2;
        max = v1;
    }

    while (true)
    {
        if (root->left != nullptr && root->data > max)
        {
            root = root->left;
            continue;
        }

        if (root->right != nullptr && root->data < min)
        {
            root = root->right;
            continue;
        }

        break;
    }

    return root;
}
