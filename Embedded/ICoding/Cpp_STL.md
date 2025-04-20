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
sorting vector: sort(vector.begin(),vector.end())
sort(arr1.begin(),arr1.begin()+2); = sort between indices 0,2 (2 not included)
sorting vector of vectors: vector<vector<int>> intervals
sort(intervals.begin(),intervals.begin()+intervals.size())
sort by x[0]: intervals.sort(key=lambda x: x[0])


List: similar to vector.
list optimized for beginning/end vs vectors-@end only and not a random access
#include <list>
list<string>names={"name1","name2"}
names.front();names.back();
names.push_front();names.push_back();
names.pop_front();names.pop_back();
names.empty();<tels if list is empty>
for(string name:names){cout<<name}

stack: LIFO
stack<string> names;
stack<string> names={"name1","name2"}
names.push("name3");names.pop();
cout<<names.top()<<names.size()

Queue: FIFO
#include<queue>
queue<string> names;
names.push("name3");names.pop();

Deque: 
deque<string> names = {"name1","name2"}
for(string name:names){cout<<name;}
name[0],name[1]
name.front();name.back();name.at(6);
name.push_back("name3");name.push_front("name0");
name.pop_front();name.pop_back();

Set: unique elements only
#include<set>
set<string> names={"name1","name2"}
names.insert("name3");names.insert("name1");
names.erase("name1")
names.size()

unordered_set: no order within set
#include<unordered_set>
unordered_set<string> names={"name1","name2"}
names.insert("name1") doesnt do anything
names.erase("name1") >> removes "name1"

map: map<key,value> and unique, sorted
#include<map>
map<string,int> people={{"name1",1},{"name2",3}}
cout<<people["name1"] or people.at("name1")
people["name3"]=5 or people.insert({"name3",5})
people.erase("name1")
people.clear() = all
people.size()
is empty? people.empty()
for(auto key:people){key.first;key.second}
map.find(key) returns ptr to key

strings
convert number to string: string number = to_string(n);

arrays
int names[4];
int names[4]={0,1,2,3}; 
cout<<names[0]<<sizeof(names)/sizeof(names[0])
int *arr = new int[n]

mutex
pthread_mutex_t m;
pthread_mutex_init(&m)
pthread_mutex_lock(&m)
pthread_mutex_unlock(&m)

conditional variable: tied to a mutex
pthread_cond_t cv
pthread_cond_init(&cv,&m)
pthread_cond_wait(&cv,&m)
pthread_cond_broadcast(&cv,&m)

concurrency:
thread1: get lock, while loop on variable, sit on cond-var, once exits, do process, 
    broadcast cond-var, unlock
thread2: same, except while loop on different value of variable
