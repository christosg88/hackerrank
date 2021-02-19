/**
 * Get Nth element from the end in a linked list of integers.
 * Number of elements in the list will always be greater than N.
 *
 * Node is defined as:
 * struct Node
 * {
 *     int data;
 *     Node *next;
 * }
 */

/**
 * Get the Nth element from the end of the linked list.
 * @param  head             a pointer to the head of the linked list
 * @param  positionFromTail the distance of the Nth node from the end of the
 *                          linked list
 * @return                  the data of the Nth Node from the end of the list
 */
int GetNode(Node *head, int positionFromTail)
{
    int size = positionFromTail + 1;
    int index = 0;
    int *nums = new int[size];

    while (head != NULL)
    {
        nums[index] = head->data;
        index = (index + 1) % size;
        head = head->next;
    }

    int to_return = nums[index];
    delete[] nums;

    return to_return;
}
