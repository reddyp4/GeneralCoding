/* Using semaphore for Circular Buffer (Queue) 
  Semaphore on both data and head/tail 
  
  Semaphore as a mutex:
  Semaphore *mutex = make_semaphore(1);

    semaphore_wait(mutex);
    // protected code goes here
    semaphore_signal(mutex);
  
  */

typedef sem_t Semaphore;

Semaphore *make_semaphore(int value);
void semaphore_wait(Semaphore *sem);
void semaphore_signal(Semaphore *sem);

typedef struct {
    int *array;
    int length;
    int next_in;
    int next_out;
    Semaphore *mutex;       //-- new
    Semaphore *items;       //-- new
    Semaphore *spaces;      //-- new
} Queue;

Queue *make_queue(int length)
{
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->length = length;
    queue->array = (int *) malloc(length * sizeof(int));
    queue->next_in = 0;
    queue->next_out = 0;
    queue->mutex = make_semaphore(1);
    queue->items = make_semaphore(0);
    queue->spaces = make_semaphore(length-1);
    return queue;
}

void queue_push(Queue *queue, int item) {
  semaphore_wait(queue->spaces);
  semaphore_wait(queue->mutex);

  queue->array[queue->next_in] = item;
  queue->next_in = queue_incr(queue, queue->next_in);

  semaphore_signal(queue->mutex);
  semaphore_signal(queue->items);
}

int queue_pop(Queue *queue) {
  semaphore_wait(queue->items);
  semaphore_wait(queue->mutex);
  
  int item = queue->array[queue->next_out];
  queue->next_out = queue_incr(queue, queue->next_out);

  semaphore_signal(queue->mutex);
  semaphore_signal(queue->spaces);

  return item;
}
