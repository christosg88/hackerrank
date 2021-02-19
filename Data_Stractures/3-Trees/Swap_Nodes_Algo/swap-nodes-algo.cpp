#include <iostream>
#include <cmath>

class node
{
public:
    int data;
    node *left;
    node *right;
    node()
    {
        this->data = -1;
        this->left = nullptr;
        this->right = nullptr;
    }
};

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

/**
 * Swap the left child with the right child recursively.
 * @param  root  the current root of the binary search tree
 * @param  depth the depth at which the children must be changed
 * @return       the total number of swaps made
 */
int Swap(node *root, int depth)
{
    int swaps = 0;

    // make sure they are not both nullptr because then there is no change
    // necessary
    if (depth == 1 && root->left != root->right)
    {
        node *tmp_node = root->left;
        root->left = root->right;
        root->right = tmp_node;
        swaps += 1;
    }
    else
    {
        if (root->left != nullptr)
            swaps += Swap(root->left, depth-1);

        if (root->right != nullptr)
            swaps += Swap(root->right, depth-1);
    }

    return swaps;
}

int main()
{
    // don't sync with the stdio
    std::ios_base::sync_with_stdio(false);

    int nodes_count;
    std::cin >> nodes_count;

    // create a binary tree in an array
    node *nodes = new node[nodes_count];
    // the nodes will always be sequential at first like that [1, 2, 3, 4, ...]
    for (int i = 0; i < nodes_count; ++i)
        nodes[i].data = i + 1;

    // the index of the next child
    int next_child = 1;

    // now we just have to configure the children of each node
    for (int i = 0; i < nodes_count; ++i)
    {
        int tmp;

        std::cin >> tmp;
        if (tmp != -1)
            nodes[i].left = &nodes[next_child++];

        std::cin >> tmp;
        if (tmp != -1)
            nodes[i].right = &nodes[next_child++];
    }

    // the number of changes (number of Ks) that we will have to make
    int changes;
    std::cin >> changes;

    // for each K
    for (int i = 0; i < changes; ++i)
    {
        // read the original depth and every time add its value to its copy, so
        // that we change at depths K, 2K, 3K, ...
        int org_depth, cpy_depth;
        std::cin >> org_depth;
        cpy_depth = org_depth;

        int swaps;
        do
        {
            swaps = Swap(&nodes[0], cpy_depth);
            cpy_depth += org_depth;
        }
        while (swaps > 0);

        // print the tree with in-order traversal
        Inorder(&nodes[0]);
        std::cout << '\n';
    }

    // cleanup
    delete[] nodes;
    return 0;
}
