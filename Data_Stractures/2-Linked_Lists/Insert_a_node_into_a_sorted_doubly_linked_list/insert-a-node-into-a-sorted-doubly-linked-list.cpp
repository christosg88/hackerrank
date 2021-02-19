/**
 * Insert Node in a sorted doubly linked list.
 * After each insertion, the list should be remain sorted.
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
 * Inserts a new node at a doubly linked list conserving the order.
 * @param  head a pointer to the head of the doubly linked list
 * @param  data the data of the new node
 * @return      a pointer to the head of the doubly linked list
 */
Node* SortedInsert(Node *head, int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    // if the list is empty return just the new node
    if (head == NULL)
        return new_node;
    // if the new_node should be inserted at the head of the linked list
    else if (head->data >= data)
    {
        new_node->next = head;
        head->prev = new_node;
        return new_node;
    }

    Node *tmp_node = head;
    while (tmp_node->data < data)
    {
        // if we reached the end of the doubly linked list
        if (tmp_node->next == NULL)
        {
            tmp_node->next = new_node;
            new_node->prev = tmp_node;
            return head;
        }

        tmp_node = tmp_node->next;
    }

    // at this point tmp_node points to the node that should be AFTER the
    // new_node
    tmp_node->prev->next = new_node;
    new_node->prev = tmp_node->prev;
    new_node->next = tmp_node;
    tmp_node->prev = new_node;

    return head;
}
