/**
 * Compare two linked lists A and B.
 * Return 1 if they are identical and 0 if they are not.
 *
 * Node is defined as:
 * struct Node
 * {
 *     int data;
 *     Node *next;
 * }
 */

/**
 * Compares two linked lists for equality. Two linked lists are considered equal
 * if they contain the same number of nodes and each pair of nodes contain the
 * same data.
 * @param  headA a pointer to the head of the first linked list
 * @param  headB a pointer to the head of the second linked list
 * @return       1 for equality else 0
 */
int CompareLists(Node *headA, Node *headB)
{
    while (true)
    {
        // if they both reached their ends, they are equal
        if (headA == NULL && headB == NULL)
            return 1;
        // else if one of them is NULL but the other is not, or if their data
        // are not equal, the lists are not equal
        else if (headA == NULL || headB == NULL || headA->data != headB->data)
            return 0;
        // else move to the next nodes on both lists
        else
        {
            headA = headA->next;
            headB = headB->next;
        }
    }
}
