/**
 * Insert Node at the beginning of a linked list.
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
 * Inserts a new Node at the beginning of the linked list.
 * @param  head a pointer to the head of the linked list
 * @param  data the data of the new Node
 * @return      a pointer to the head of the linked list
 */
Node* Insert(Node *head, int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return head;
}
