#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node
{
    Node *prev;
    Node *next;
    int key;
    int value;
    Node(Node *p, Node *n, int k, int val) : prev(p), next(n), key(k), value(val) {};
    Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache
{
protected:
    std::map<int, Node *> mp;   // map the key to the node in the linked list
    unsigned int cp;            // capacity
    Node *tail;                 // double linked list tail pointer
    Node *head;                 // double linked list head pointer
    virtual void set(int, int) = 0; // set function
    virtual int get(int) = 0;   // get function
};

class LRUCache : protected Cache
{
public:
    explicit LRUCache(int capacity)
    {
        cp = capacity;
        tail = NULL;
        head = NULL;
    }

    ~LRUCache()
    {
        while (head != NULL)
        {
            Node *node_pt = head;
            head = head->next;
            delete node_pt;
        }
    }

    /**
     * If key is in the cache, update the value, else create a new pair and add
     * it to the beginning.
     * @param key   the key of the pair
     * @param value the value of the pair
     */
    virtual void set(int key, int value)
    {
        if (head == NULL)   // if there is no element in cache, add this first
        {
            Node *new_node = new Node(key, value);  // create a new node
            head = tail = new_node;
            mp.insert(std::pair<int, Node *>(key, new_node));   // insert the new node in the map
            return;
        }
        else    // there is at least one element in cache
        {
            std::map<int, Node *>::iterator map_it = mp.find(key);
            if (map_it != mp.end())     // the key is already in the cache
            {
                map_it->second->value = value;  // update the value
            }
            else    // the new pair <key, value> should be inserted at the beginning
            {
                Node *new_node = new Node(NULL, head, key, value);  // create a new node
                head->prev = new_node;  // change the old head's prev to new_node
                head = new_node;    // change head to point to the new head
                mp.insert(std::pair<int, Node *>(key, new_node));   // insert the new node in the map

                if (mp.size() > cp)     // we have exceeded the cache's capacity
                {
                    Node *to_delete = tail; // save the pointer of the last element to delete it later
                    tail = tail->prev; // make the the tail point to the new last element
                    tail->next = NULL;  // make the new tail's n pointer point to NULL
                    // get an iterator to the element to be deleted in mp
                    std::map<int, Node *>::iterator map_it = mp.find(to_delete->value);
                    mp.erase(map_it);   // erase the element from mp
                    delete to_delete;   // delete the Node itself
                }
            }
        }
    }

    /**
     * Get the value of the pair with key key, if it exists, otherwise, add the
     * key as a new pair with value -1 at the beginning of the cache
     * @param  key the key of the pair
     * @return     the value of the pair if it exists, otherwise -1
     */
    virtual int get(int key)
    {
        std::map<int, Node *>::iterator map_it = mp.find(key);

        if (map_it == mp.end()) // the key wasn't in mp
        {
            // add the new key at the beginning of the cache with value -1
            set(key, -1);
            return -1;
        }
        else    // the key was in mp, so we have to update the linked list
        {
            Node *to_be_head = map_it->second;
            if (to_be_head != head) // if it's not already the head
            {
                if (to_be_head->prev != NULL)
                    to_be_head->prev->next = to_be_head->next;
                if (to_be_head->next != NULL)
                    to_be_head->next->prev = to_be_head->prev;
                to_be_head->next = head;
                to_be_head->prev = NULL;
                head = to_be_head;
            }

            return head->value;
        }
    }
};

int main()
{
    int n, capacity;
    std::cin >> n >> capacity;

    LRUCache l(capacity);

    for (int i = 0; i < n; i++)
    {
        std::string command;
        std::cin >> command;

        if (command == "get")
        {
            int key;
            std::cin >> key;
            std::cout << l.get(key) << endl;
        }
        else if (command == "set")
        {
            int key, value;
            std::cin >> key >> value;
            l.set(key, value);
        }
    }

    return 0;
}
