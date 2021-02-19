/**
 * Reverse a linked list and return pointer to the head.
 * The input list will have at least one element.
 *
 * Node is defined as:
 * struct Node
 * {
 *     int data;
 *     Node *next;
 * }
 */

/**
 * Reverse a linked list.
 * @param  head a pointer to the head of the linked list
 * @return      a pointer to the head of the linked list
 */
Node* Reverse(Node *head)
{
    // if there is one or none nodes after this node, we are finished
    if (head == NULL || head->next == NULL)
        return head;

    Node *newHead = Reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}
