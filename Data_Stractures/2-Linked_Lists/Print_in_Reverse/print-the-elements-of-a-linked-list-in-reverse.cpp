/**
 * Print the linked list in reverse order.
 *
 * Node is defined as:
 * struct Node
 * {
 *     int data;
 *     Node *next;
 * }
 */

/**
 * Prints the linked list in reverse order, with each node in a new line.
 * @param head a pointer to the head of the linked list
 */
void ReversePrint(Node *head)
{
    if (head == NULL)
        return;
    else
    {
        ReversePrint(head->next);
        std::cout << head->data << '\n';
    }
}
