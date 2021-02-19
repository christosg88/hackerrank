/**
 * Insert Node at a given position in a linked list.
 * Head pointer input could be NULL if the list is empty.
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
 * Inserts a new Node at a specific location in the linked list.
 * @param  head     a pointer to the head of the linked list
 * @param  data     the data of the new Node
 * @param  position the position in the linked list where the new Node should be
 *                  put
 * @return          a pointer to the head of the linked list
 */
Node* InsertNth(Node *head, int data, int position)
{
    Node *new_node = new Node;
    new_node->data = data;

    // if the new_node should be the new head
    if (position == 0)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        Node *traverse_node = head;

        for (int i = 0; i < position - 1; ++i)
            traverse_node = traverse_node->next;

        new_node->next = traverse_node->next;
        traverse_node->next = new_node;
    }

    return head;
}
