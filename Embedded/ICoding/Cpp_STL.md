C++ STL:
Vectors: dynamic array
List: Linked List
Stack: Elements in LIFO
Queue: Elements in FIFO
Deque: Double ended Queue, LIFO+FIFO
Set: Unique elements
Map: Key-value pairs

Vector:
#include <vector>
vector<string> names = {"name1","name2"};
names[0];names.at(0)
names.front(); names.back()
names[1]="name1"
names.push_back("name3")
names.pop_back(); //remove last
names.size();names.empty()
for(string name: names){cout<<name}
