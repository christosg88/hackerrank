/**
 * Delete Node at a given position in a linked list.
 * First element in the linked list is at position 0.
 *
 * Node is defined as:
 * struct Node
 * {
 *     int data;
 *     Node *next;
 * }
 */

/**
 * Deletes the node at the given position.
 * @param  head     a pointer to the head of the linked list
 * @param  position the position of the node to be deleted
 * @return          a pointer to the head of the linked list
 */
Node* Delete(Node *head, int position)
{
    // if the head has to be deleted
    if (position == 0)
    {
        Node *tmp_node = head;
        head = head->next;
        delete tmp_node;
    }
    else
    {
        Node *traverse_node = head;
        Node *tmp_node;
        for (int i = 0; i < position - 1; ++i)
            traverse_node = traverse_node->next;

        tmp_node = traverse_node->next;
        traverse_node->next = traverse_node->next->next;
        delete tmp_node;
    }

    return head;
}
