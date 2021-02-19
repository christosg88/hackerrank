/**
 * struct node
 * {
 *     int freq;
 *     char data;
 *     node *left;
 *     node *right;
 * };
 */

void decode_huff(node *root, string s)
{
    node *traverse_node = root;

    int i = 0;
    int len = s.length();

    while (i < len)
    {
        if (s[i] == '1')
            traverse_node = traverse_node->right;
        else
            traverse_node = traverse_node->left;

        if (traverse_node->data != '\0')
        {
            std::cout << traverse_node->data;
            traverse_node = root;
        }

        i++;
    }

    std::cout << '\n';
}
