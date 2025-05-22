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
class LRUCache {
public:
    map<int,int> myCache;   //map<key,value>
    queue<int> myQ; //Q of keys
    int len,cap;
    LRUCache(int capacity) {
        len=0;
        cap=capacity;
    }
    
    int get(int key) {
        //search for key - if map, search using count O(1)
        if(myCache.count(key)==1)
        {
            myQ.push(key);
            myQ.pop();
            int val = myCache[key];
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //search for key - if map search O(n)
        if(myCache.count(key)==1)
        {
            myQ.push(key);
            myQ.pop();
            myCache[key]=value;
        }
        else
        {
            if(len==cap)
            {
                myCache.erase(myQ.front());
                myQ.pop();len--;
            }
            myCache[key]=value;
            myQ.push(key);
            len++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */