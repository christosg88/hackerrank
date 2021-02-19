#include <iostream>
#include <climits>
#include <random>

#include "implicit_treap.h"
#include "print_binary_tree.h"

/**
 * Prints the values of the binary tree in in-order traversal.
 * @param root a pointer to the root of the binary tree
 */
void Inorder(node *root)
{
    if (root == nullptr)
        return;

    if (root->left != nullptr)
        Inorder(root->left);

    std::cout << root->val << ' ';

    if (root->right != nullptr)
        Inorder(root->right);
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    unsigned long len, queries;
    std::cin >> len >> queries;

    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<unsigned long> dist(0, std::numeric_limits<unsigned long>::max());

    node *root = nullptr;

    root = insert(root, new node(105, dist(gen)));
    root = insert(root, new node(110, dist(gen)));
    root = insert(root, new node(90, dist(gen)));
    root = insert(root, new node(100, dist(gen)));
    root = insert(root, new node(200, dist(gen)));
    root = insert(root, new node(105, dist(gen)));
    root = insert(root, new node(107, dist(gen)));
    root = insert(root, new node(106, dist(gen)));
    root = insert(root, new node(101, dist(gen)));
    root = insert(root, new node(201, dist(gen)));

    printPretty(root, 1, 0, std::cout);

    // Create a file and output to that file
    std::ofstream fout("tree_pretty.txt");
    // Now print a tree that's more spread out to the file
    printPretty(root, 1, 0, fout);


    // for (unsigned long i = 0; i < len; ++i)
    // {
    //     unsigned long val;
    //     std::cin >> val;
    //     root = insert(root, new node(val, dist(gen)));
    // }

    // for (unsigned long i = 0; i < queries; ++i)
    // {
    //     short operation;
    //     long a, b;
    //     std::cin >> operation >> a >> b;

    //     node *t1, *t2, *t3;
    //     split(root, t1, t2, a-2);
    //     split(t2, t2, t3, b-a);

    //     if (operation == 1)
    //         root = merge(t2, merge(t1, t3));
    //     else
    //         root = merge(merge(t1, t3), t2);
    // }

    // std::cout << std::abs(get_val(root, 0) - get_val(root, len - 1)) << '\n';

    // Inorder(root);
    // std::cout << '\n';

    empty(root);

    return 0;
}
