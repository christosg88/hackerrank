/**
 * Merge two sorted lists A and B as one linked list.
 *
 * Node is defined as:
 * struct Node
 * {
 *     int data;
 *     Node *next;
 * }
 */

/**
 * Merges the two sorted linked lists conserving the order
 * @param  headA a pointer to the head of the first linked list
 * @param  headB a pointer to the head of the second linked list
 * @return       a pointer to the head of the merged linked list
 */
Node* MergeLists(Node *headA, Node *headB)
{
    Node *new_head;
    Node *head_to_smaller, *head_to_bigger;
    // find which of the two linked lists starts with the minimum number
    if (headA != NULL && headB != NULL)
    {
        if (headA->data < headB->data)
        {
            head_to_smaller = new_head = headA;
            head_to_bigger = headB;
        }
        else
        {
            head_to_smaller = new_head = headB;
            head_to_bigger = headA;
        }
    }
    else if (headA != NULL)
        return headA;
    else
        return headB;

    Node *tmp_node;
    while (head_to_smaller != NULL && head_to_bigger != NULL)
    {
        // check if the next node of current head_to_smaller will point to its
        // next node or the node pointed by head_to_bigger
        if (head_to_smaller->next == NULL)
        {
            head_to_smaller->next = head_to_bigger;
            break;
        }
        else if (head_to_smaller->next->data > head_to_bigger->data)
        {
            tmp_node = head_to_smaller->next;
            head_to_smaller->next = head_to_bigger;
            head_to_smaller = tmp_node;
        }
        else
        {
            head_to_smaller = head_to_smaller->next;
        }

        // check if head_to_smaller and head_to_bigger need to be exchanged
        if (head_to_smaller->data > head_to_bigger->data)
        {
            tmp_node = head_to_smaller;
            head_to_smaller = head_to_bigger;
            head_to_bigger = tmp_node;
        }
    }

    return new_head;
}
