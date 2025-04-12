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

strings

arrays
int names[4];
int names[4]={0,1,2,3};
cout<<names[0]<<sizeof(names)/sizeof(names[0])
int *arr = new int[n]
