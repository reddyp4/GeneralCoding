/* Single producer, multiple consumer queue 
Also called a bounding block queue 

Implement a thread-safe bounded blocking queue that has the following methods:

BoundedBlockingQueue(int capacity) The constructor initializes the queue with a 
maximum capacity.

void enqueue(int element) Adds an element to the front of the queue. 
If the queue is full, the calling thread is blocked until the queue is no 
longer full.

int dequeue() Returns the element at the rear of the queue and removes it. 
If the queue is empty, the calling thread is blocked until the queue is no 
longer empty.

int size() Returns the number of elements currently in the queue.

source: https://leetcode.com/problems/design-bounded-blocking-queue/description/
*/

class BoundedBlockingQueue
{
    public:
    BoundedBlockingQueue(int capacity)
    : cap_(capacity)
    {
    }

    void enqueue(int element)
    {
        std::unique_lock<std::mutex> lk(mutex);
        is_full.wait(lk, [this])
        {
            return queue.size()<capacity;
        }
        content.push_back(element);
        not_empty.notify_all();
    }

    int dequeue()
    {
        int element;
        std::unique_lock<std::mutex> lk(mutex);
        not_empty.wait(lk, [this])
        {
            return !content.empty();
        }
        not_fully.notify_all();
    }

    private:
        std::mutex mut;
        std::condition_variable not_full;
        std::condition_variable not_empty;
        std::queue content;
}