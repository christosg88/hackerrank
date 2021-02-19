/**
 * Remove all duplicate elements from a sorted linked list.
 *
 * Node is defined as:
 * struct Node
 * {
 *     int data;
 *     Node *next;
 * }
 */

/**
 * Removes all the nodes with duplicate data.
 * @param  head a pointer to the head of the linked list
 * @return      a pointer to the head of the linked lists
 */
Node* RemoveDuplicates(Node *head)
{
    Node* traverse_node = head;
    while (traverse_node != NULL)
    {
        while (traverse_node->next != NULL && traverse_node->next->data == traverse_node->data)
        {
            Node *tmp_node = traverse_node->next;
            traverse_node->next = traverse_node->next->next;
            delete tmp_node;
        }

        traverse_node = traverse_node->next;
    }

    return head;
}
