/**
 * Reverse a doubly linked list, input list may be empty.
 *
 * Node is defined as:
 * struct Node
 * {
 *     int data;
 *     Node *next;
 *     Node *prev;
 * }
 */

/**
 * Reverses a doubly linked list.
 * @param  head a pointer to the head of the doubly linked list
 * @return      a pointer to the new head of the doubly linked list
 */
Node* Reverse(Node *head)
{
    // if the list doesn't have to be reversed
    if (head == NULL || head->next == NULL)
        return head;

    Node *traversing_node = head;
    do
    {
        // swap the next with the prev pointers
        Node *tmp_node = traversing_node->prev;
        traversing_node->prev = traversing_node->next;
        traversing_node->next = tmp_node;

        // if the current node's next pointer points to NULL, current node is
        // the head of the linked list, so return it
        if (traversing_node->prev == NULL)
            return traversing_node;
        // else go to the next node and keep reversing
        else
            traversing_node = traversing_node->prev;
    }
    while (true);
}
