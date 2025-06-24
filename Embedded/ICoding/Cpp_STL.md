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
Declare: vector<string> names = {"name1","name2"};
Declare fixed size: vector<int> names(5,9);     //five elements default value of 9
Define at different time as declare:
class PhoneDirectory{
    public: 
        vector<int> phone;
        int len;
        PhoneDirectory(int Numbers):phone(Numbers) {len=Numbers;}
}
Addng to end
Get max: 
Sum: accumulate(names.begin(),names.end(),0)

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
accessing elements in intervals: intervals[i][0] .. intervals[i][1]

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
Create: queue<string> names={"name1","name2"};
Initialize with defaul values: Cannot be done
Add: names.push("name3");
Access: names.front() and names.back()
Change front and back: names.front()="name4", names.back()="name5"
Remove: names.pop();
Get size: names.size()
Empty: names.empty()

Deque: 
Create: deque<string> names = {"name1","name2"}
Create: for(string name:names){cout<<name;}
Access front or back: name.front();name.back();
Access a particular element: name.at(6);name[0],name[1]
Push from or back: name.push_back("name3");name.push_front("name0");
Clear all deque: name.clear()
Remove one element: name.pop_back() or name.pop_front()
Check if empty: name.empty()
Iterator to an index: names.begin()+i

Set: unique elements only
#include<set>
set<string> names={"name1","name2"}
names.insert("name3");names.insert("name1");
names.erase("name1")
names.size()
check if in set: 

unordered_set: no order within set
#include<unordered_set>
unordered_set<string> names={"name1","name2"}
names.insert("name1") doesnt do anything
names.erase("name1") >> removes "name1"
check if in set: 

map: map<key,value> and unique, sorted
#include<map>
Declare: map<string,int> people={{"name1",1},{"name2",3}}
Insert: people.insert({"name3",3})
Access elements: people["name3"]=5 OR people.at("name1")
Update elements: people["name3"]=10 OR people.at("name1")=10
Finding elements: for(auto key:people){key.first;key.second}
    auto itmap.find(key); 
    if(it!=people.end()) cout<<"not found"<<endl;
Finding if key O(1) is present: 
    if(people.count(key)>0)   .count returns 1 if present, else 0
    OR 
    if(people.find(key)!=people.end())  .find returns iterator to element, if not .end()
Remove elements: people.erase("name1")
Remove all: people.clear() = all
Get size: people.size()
Check empty: is empty? people.empty()

SPARSE MATRIX: Using hash_map of hash_maps, can store non-zero elements
1) unordered_map<pair<int,int>,int> sparseMatrix
              row               column
    Insert: sparseMatrix[{0,2}]=5;
    Check if element exists: if(sparseMatrix.find({1,3})!=sparseMatrix.end())   cout<<"Exists"<<endl;
    Check2: if(sparseMatrix.count({1,3})>0) cout<<"Exists"<<endl;

    //Iterate non-zero elements
    for(const auto& rowPointer:sparseMatrix) {
        row=rowPointer.first;
        for(const auto& colPointer:(rowPair.second)){
            col=sparseMatrix(row).first;
            val=sparseMatrix(row).second;
        }
    }
2) unordered_map<int,unordered_map<int,double>> matrix;
    Insert: matrix[row][col]=value;
    Find value at row,col: auto row_it = matrix.find(row);
                            if(row_it!=matrix.end()) {
                                auto col_it = row_it->second.find(col);
                            }

HASH MAP for string,string to key
1) #include <unordered_map>
    unordered_map<pair<string,string>,int>  lookup;
    Access element: lookup[{"str1","str2"}] = 2
    Is element present: lookup.count([{"str1","str2"}])>0
        OR lookup.find({"str1","str2"})!=lookup.end()
    Iterate through elements: for(const auto&pair : lookup) {pair.first.first;pair.first.second;}

strings
convert number to string: string number = to_string(n);
example:
convert to upper:
check lower: tolower()
sub-string: .substr(start,length)
sort string lexicographically: 


arrays
int names[4];
int names[4]={0,1,2,3}; 
cout<<names[0]<<sizeof(names)/sizeof(names[0])
int *arr = new int[n]

STRUCTURES:
struct Node {
    int key,value;
    Node *prev, *next;
    //assign class of structure
    Node(int key,int val): key(key), value(val),next(nullptr),prev(nullptr) {}
};
Call: Node* head = new Node(-1,-1);

CONCURRENCY:
mutex
pthread_mutex_t m;
pthread_mutex_init(&m,NULL)
pthread_mutex_lock(&m)
pthread_mutex_unlock(&m)

conditional variable: tied to a mutex
pthread_cond_t cv
pthread_cond_init(&cv,NULL)
pthread_cond_wait(&cv,&m)
pthread_cond_broadcast(&cv,&m)

include<semaphore.h>
sem_t sm;
sem_init(&sm,0,0)
sem_wait(&sm)
sem_post(&sm)

thread1: get lock, while loop on variable, sit on cond-var, once exits, do process, 
    broadcast cond-var, unlock
thread2: same, except while loop on different value of variable
