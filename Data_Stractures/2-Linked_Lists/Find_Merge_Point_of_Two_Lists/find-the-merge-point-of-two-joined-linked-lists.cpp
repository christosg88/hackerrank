/**
 * Find the merge point of two linked lists.
 *
 * Node is defined as:
 * struct Node
 * {
 *     int data;
 *     Node *next;
 * }
 */

/**
 * Finds the merging node of the two linked lists.
 * @param  headA a pointer to the head of the first linked list
 * @param  headB a pointer to the head of the second linked list
 * @return       the data of the merging node
 */
int FindMergeNode(Node *headA, Node *headB)
{
    Node *currentA = headA;
    Node *currentB = headB;

    while (currentA != currentB)
    {
        currentA = currentA == NULL ? headB : currentA->next;
        currentB = currentB == NULL ? headA : currentB->next;
    }

    return currentA->data;
}
