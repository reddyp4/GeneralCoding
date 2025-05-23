/*
211. Design Add and Search Words Data Structure
Attempted
Medium
Topics
Companies
Hint
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 25
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 2 dots in word for search queries.
At most 104 calls will be made to addWord and search.
*/

/*
linked list: struct Node {   string val; Node* next;};
checking for dots: check before, after string for every dot
However this solution doesnt pass for longer test cases, time expires
*/

struct Node {
    string value;
    Node *next,*prev;
    Node(string given): value(given), next(nullptr),prev(nullptr) {}
};

class WordDictionary {
public:
    Node *head = new Node("");
    Node *tail = new Node("");
    WordDictionary() {
        head->next=tail;
        tail->prev=head;
    }
    
    void addWord(string word) {
        Node *node = new Node(word);
        node->next=tail;
        node->prev=tail->prev;
        node->prev->next = node;
        tail->prev = node;
    }
    
    bool search(string word) {
        int len1=word.size(),i=0,match=1;
        Node *node=head->next;
        while(node!=tail)
        {
            //cout<<"word:"<<word<<",dict:"<<node->value<<",word.size:"<<word.size()<<",node.size:"<<node->value.size()<<endl;
            if(word.size()!=(node->value).size())   {node=node->next;continue;}
            if(node->value==word) {/*cout<<"matched word"<<endl;*/return true;}
            i=0;match=1;
            while(i<len1 && match==1)
            {
                //cout<<"i:"<<i<<"word[i]:"<<word[i]<<",node[i]:"<<(node->value)[i]<<endl;
                if(word[i]=='.')    {i++;continue;}
                if(word[i]!=((node->value)[i]))   {/*cout<<"no match:"<<word[i]<<",node[i]:"<<(node->value)[i]<<endl;*/match=0;}
                i++;
            }
            //cout<<"finished word:"<<word<<",dict:"<<node->value<<",match:"<<match<<endl;
            if(match==1)    return true;
            node=node->next;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
