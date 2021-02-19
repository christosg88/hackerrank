#include "implicit_treap.h"

node::node(long val, unsigned long prior)
{
    this->val = val;
    this->prior = prior;
    this->size = 0;
    this->left = nullptr;
    this->right = nullptr;
}

/**
 * Merges two treaps into one, maintaining the trap properties
 * @param  l a pointer to the root of the left treap
 * @param  r a pointer to the root of the right treap
 * @return   a pointer to the root of the resulting treap
 */
node *merge(node *l, node *r)
{
    // if one of the roots is nullptr, return the pointer of the other treap as
    // the root of the resulting treap
    if (l == nullptr)
    {
        update_size(r);
        return r;
    }
    else if (r == nullptr)
    {
        update_size(l);
        return l;
    }

    // if the root of the l treap has greater priority than the root of the r
    // treap
    if (l->prior > r->prior)
    {
        // assign to the right child of the l treap, the merge of the right
        // child of the l treap, with the r treap
        l->right = merge(l->right, r);
        // update the size of l
        update_size(l);
        // and return as root the root of the l treap
        return l;
    }
    // else the r treap has greater priority
    else
    {
        // assign to the left child of the r treap, the merge of the l treap,
        // with the left child of the r treap
        r->left = merge(l, r->left);
        // update the size of r
        update_size(r);
        // and return as root the root of the r treap
        return r;
    }
}

/**
 * Splits the treap into two treaps, at the specified index. The node with the
 * specified index will be at the root of the l treap.
 * @Requires: The pos should be between [0, len-1] where len is the length of
 * the treap array.
 * @param root a pointer to the root of the treap
 * @param l    the reference of the pointer to the root of the l treap
 * @param r    the reference of the pointer to the root of the r treap
 * @param pos  the index of the node where the split shall be made
 * @param add  (default: 1) add this to get the current position
 */
void split(node *root, node * &l, node * &r, long pos, long add/* = 1*/)
{
    if (root == nullptr)
    {
        l = r = nullptr;
        return;
    }
    else if (pos == -1)
    {
        l = nullptr;
        r = root;
        return;
    }

    // the index of the current node in the treap array
    long curr_pos = add + size(root->left);

    // if we are at the node with the specified position
    if (pos == curr_pos)
    {
        // the l tree will start at root, with its right child clipped
        l = root;
        // the r tree will start at the right child of the root
        r = root->right;
        // clip the right child of the l treap
        l->right = nullptr;

        update_size(l);
    }
    // if the position is smaller than the current position
    else if (pos < curr_pos)
    {
        // split at the left sub-treap, and make the root->left point to where
        // the r in the recursive call will point
        split(root->left, l, root->left, pos, add);
        r = root;
        update_size(r);
    }
    // else the position is greater than the current position
    else
    {
        // split at the right sub-treap, and make the root->right point to where
        // the l in the recursive call will point
        split(root->right, root->right, r, pos, curr_pos + 2);
        l = root;
        update_size(l);
    }
}

/**
 * Inserts a new node in the treap.
 * @param  root     a pointer to the root of the treap
 * @param  new_node a pointer to the new node to be inserted
 * @return          a pointer to the root after the insertion
 */
node *insert(node *root, node *new_node)
{
    return merge(root, new_node);
}

/**
 * Removes the node at index pos from the treap.
 * @Requires: The pos should be between [0, len-1] where len is the length of
 * the treap array.
 * @param  root a pointer to the root of the treap
 * @param  pos  the index of the node we want to remove
 * @return      a pointer to the new root of the treap
 */
node *remove(node *root, long pos)
{
    node *t1, *t2, *t3;
    split(root, t1, t2, pos-1);
    split(t2, t2, t3, 0);

    delete t2;

    return merge(t1, t3);
}

/**
 * Returns the val of the node at pos index.
 * @param  root a pointer to the root of the treap
 * @param  pos  the index of the node whose value will be returned
 * @param  add  (default: 1) add this to get the current position
 * @return      the val of the node at pos index
 */
long get_val(node *root, long pos, long add/* = 1*/)
{
    // the current index in the array of this node
    long curr_pos = add + size(root->left);

    // if you found the node with the specified position
    if (curr_pos == pos)
        return root->val;
    // if the current position is greater than the needed one, go to the left of
    // the root
    else if (pos < curr_pos)
        return get_val(root->left, pos, add);
    // else the current position is smaller than the needed one, so go to the
    // right of the root
    else
        return get_val(root->right, pos, curr_pos + 2);
}

/**
 * Deletes all the nodes in the treap.
 * @param  root a pointer to the root of the treap
 */
void empty(node *root)
{
    if (root == nullptr)
        return;

    empty(root->left);
    empty(root->right);
    delete root;

    return;
}

/**
 * Returns the size of the given node (that is the number of descendant nodes).
 * It's 0 for a leaf and -1 for a nullptr node.
 * @param  root a pointer to the root of the treap whose size we are to find
 * @return      the number of descendants of this node
 */
long size(node *root)
{
    return root == nullptr ? -1 : root->size;
}

/**
 * Updates the size of the given node (that is the number of descendant nodes).
 * It's 0 for a leaf and -1 for a nullptr node.
 * @param root a pointer to the root of the treap whose size we are to find
 */
void update_size(node *root)
{
    root->size = 2 + size(root->left) + size(root->right);
}
