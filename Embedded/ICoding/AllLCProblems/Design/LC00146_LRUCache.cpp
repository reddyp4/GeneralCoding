/*
146. LRU Cache
Solved
Medium
Topics
Companies

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

 

Constraints:

    1 <= capacity <= 3000
    0 <= key <= 104
    0 <= value <= 105
    At most 2 * 105 calls will be made to get and put.


*/

/**
get should O(1) (if key is present) = hash-map
put should O(1) (just add key to map) = hash-map

LRU: option1: huge array with all keys pre-assigned to -1, no need to search for key
    option2: deq (queue) of all keys, search for key in deq, and return cache[key]
    option2: another map with occurence?
    put value in map, push key to front of queue? or update count of key?


*/
/**
get should O(1) (if key is present) = hash-map
put should O(1) (just add key to map) = hash-map

LRU: option1: huge array with all keys pre-assigned to -1, no need to search for key
    option2: deq (queue) of all keys, search for key in deq, and return cache[key]
    option2: another map with occurence?
    put value in map, push key to front of queue? or update count of key?


*/
/* dll=doubly linked list, in C++ = std::list
get:
    if element in hash-map, 
        read value
        remove key location in dll and put in front
        for easy access, can use another hash-map for location
        return value
    else return -1
put:    similar to get, except when hitting the limit
    if element in hash-map
        update value
        remove key location in dll (list), put in front
        for easy access, can use another hash-map for location
        return
    else
        if(full)
            remove lru=last element in dll(list), remove in location hash and cache
            update length
        add in cache hashmap
        insert in front of list
        add location of front of list
*/

//make a node for LRU cache first
struct Node {
    int key,value;
    Node *prev, *next;
    //assign class of structure
    Node(int key,int val): key(key), value(val),next(nullptr),prev(nullptr) {}
};

class LRUCache {
public:
    int cap;
    //Cache
    map<int,Node*> myCache;     //Note Cache is not key-value but key-Node
    //Declare head/tail
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    //add node at tail, tail is most recently used
    void insert(Node *node)
    {
        Node *last=tail->prev;
        last->next=node;
        node->next=tail;
        tail->prev=node;
        node->prev=last;
    }

    void remove(Node *node)
    {
        (node->prev)->next=node->next;
        (node->next)->prev=node->prev;
    }

    int get(int key) {
        //if key not in hashmap, return -1
        if(myCache.find(key)==myCache.end())    return -1;
        //find key in linked list, remove the node and push to start
        Node *node = myCache[key];
        remove(node);   //removes node
        insert(node);   //add node at head
        return node->value;
    }
    
    void put(int key, int value) {
        if(myCache.find(key)!=myCache.end())
        {
            //element already present
            Node *node=myCache[key];
            remove(node);   //to be later added in front
        }
        Node *newNode = new Node(key,value);
        myCache[key]=newNode;
        insert(newNode);    //addes to front
        //check overfill
        if(myCache.size()>cap)
        {
            //remove lru = node before tail
            Node *temp = head->next;
            remove(temp);
            myCache.erase(temp->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */