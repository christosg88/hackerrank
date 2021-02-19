#ifndef __IMPLICIT_TREAP_H_INCLUDED__
#define __IMPLICIT_TREAP_H_INCLUDED__

/**
 * A structure used for the implementation of a treap.
 */
class node
{
public:
    node(long val, unsigned long prior);
    unsigned long prior;    // the priority of the node (randomly generated)
    long val;               // the value of the node
    long size;              // the number of nodes beneath this node
    node *left;             // a pointer to the left child of this node
    node *right;            // a pointer to the right child of this node
};

// treap operations
node *merge(node *l, node *r);
void split(node *root, node * &l, node * &r, long pos, long add = 1);
node *insert(node *root, node *new_node);
node *remove(node *root, long pos);
long get_val(node *root, long pos, long add = 1);
void empty(node *root);

// helper functions
long size(node *root);
void update_size(node *root);

#endif
// __IMPLICIT_TREAP_H_INCLUDED__
