/**
 * Detect loop in a linked list.
 * The input list might be empty.
 *
 * Node is defined as:
 * struct Node
 * {
 *     int data;
 *     Node *next;
 * }
 */

/**
 * Checks if there is a cycle in the linked list using Brent's Algorithm.
 * https://en.wikipedia.org/wiki/Cycle_detection#Brent.27s_algorithm
 * http://www.siafoo.net/algorithm/11
 * @param  head a pointer to the head of the linked list.
 * @return      1 if there is a linked list, else 0.
 */
int HasCycle(Node *head)
{
    Node *turtle, *hare;
    turtle = hare = head;

    int max_steps = 2;
    int steps = 0;

    // while hare isn't at the end of the list
    while (hare != NULL)
    {
        // move hare to the next node
        hare = hare->next;
        // increment the steps taken
        steps++;
        // if the hare and the turtle are at the same node, a cycle has been
        // detected
        if (hare == turtle)
            return 1;
        // if the steps have reached the max number of steps
        if (steps == max_steps)
        {
            // teleport the turtle where the hare is
            turtle = hare;
            // double the number of the max_steps
            max_steps *= 2;
            // reset the number of steps taken to 0
            steps = 0;
        }
    }

    return 0;
}
