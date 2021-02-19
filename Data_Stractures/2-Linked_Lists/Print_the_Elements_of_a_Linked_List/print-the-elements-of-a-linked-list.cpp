/**
 * Print elements of a linked list on console.
 * Head pointer input could be NULL if the list is empty.
 *
 * Node is defined as:
 * struct Node
 * {
 *     int data;
 *     Node *next;
 * }
 */

/**
 * Prints the linked list node by node with each node on a new line
 * @param head a pointer to the head of the linked list
 */
void Print(Node *head)
{
    Node *traverse_node = head;
    while (traverse_node != NULL)
    {
        std::cout << traverse_node.data << '\n';
        traverse_node = traverse_node.next;
    }
}
