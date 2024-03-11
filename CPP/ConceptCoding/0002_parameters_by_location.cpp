/*

How is data stored in memory?

stack
.. grows down

... grows up
heap - area where malloced space is present

read-modify write - things like static variables

read-only - things like const variables

code area - main

Two things for this file:

1) String: define and see where the block exists
what is the size of string?
what if there is no null character at end

2) test: to check stack overflow


*/

#include<iostream>
#include<string>
#include<stdlib.h>
#include<string.h>

using namespace std;

// Checking stack overflow
struct StackFrame
{
    char frame_start[0];
    char buffer[4*1024];
    char frame_end[0];
    int offset = 0;

    int push(char ch)
    {
        if((buffer+offset) >= frame_end)
        {
            cout << "stack overflow" << endl;
            return 0;
        }
        buffer[offset++]=ch;
        return 1;
    }
    char front()    { return buffer[offset-1];}
    void pop()
    {
        offset--;
    }
    bool empty()    { return offset=0; }
};

StackFrame stk;
void test()
{
    while(stk.push('a') == 1)
    {}
    while(!stk.empty())
    {
        cout<< stk.front();
        stk.pop();
    }
}

class myString
{
    public:

    /* declare variable/method as public */
    char *myStr;        //Declare a pointer for bigger strings
    char thisStr[16];   //For strings less than 16 bytes
    int m_len;     //Length of string is needed, to be able to store \0 mid

    /* Constructor */
    myString(std::string a)
    {
        int thisLength = a.length();
        m_len = thisLength;
        if(thisLength<16)
        {
            // for shorter strings use a temp buffer
            // this because string library will push to read-modify area otherwise
            memcpy(thisStr, a.c_str(), thisLength); //Copy to buffer
            thisStr[thisLength]='\0';   //End with null character
            myStr = thisStr;    //Point the string pointer
            return;
        }
        myStr = (char *)malloc(thisLength); //declare space for less than 16
        for(int i=0;i<thisLength;i++)   //Copy byte by byte
            *(myStr+i)=a[i];
    }

    /* destructor */
    ~myString()
    {
        if(m_len>=16)
            free(myStr);
    }

    int length()
    {
        return m_len;
    }
};

int main()
{
    test();

    /* static */
    static char global_arr[] = "apple";     //where does it get stored? after main rw modify
    cout << "static at " << "size:" << sizeof(global_arr) << " at " << hex<< ((long long )global_arr) << endl;
    /* const sits in read-only  */
    const char *pstr = "123456789012345";
    cout << "const ptr sits at " << hex << ((long long) pstr) << endl;

    /* main */
    cout<< "Main sits at " << hex << ((long long) main) << endl;

    /* heap */
    std::string a="123456789012345";
    a[9]='\0';
    myString s(a);
    cout << "Heap at " << s.myStr << " size: " << s.m_len << endl;
    cout << "string (a) " << hex << ((long long) a.c_str()) << ", size: "  << a.length() << endl;
    return 0;
}

/*

// Compiled with: g++ -Wall -std=c++14 -pthread

#include <iostream>
#include <string>
#include<stdlib.h>
#include<string.h>

using namespace std;

// 64 bit machines


struct StackFrame {
  
    char frame_start[0];
    char buffer[4*1024];
    char frame_end[0];
    int  offset = 0;
    
    int push(char ch) {
        if ((buffer+offset) >= frame_end) {
            cout << "stack overflow" << endl;
            return 0;
        }
        buffer[offset++] = ch;
        return 1;
    }
    char front() { return buffer[offset-1]; }
    void pop() {
        offset--;
    }
    bool empty() { return offset == 0; }
};

StackFrame stk;
void test() {
 
    while(stk.push('a') == 1) {
    }
    while(!stk.empty()) {
        cout << stk.front();
        stk.pop();
    }
}

class MyString {
     public:
    
   char *myStr;
   int m_len;
   char buffer[16];
    
    MyString(string a) {
        int lena = a.length();
        if (lena < 16) {
            memcpy(buffer, a.c_str(), lena);
            buffer[lena] = '\0';
            myStr = buffer;
            m_len = lena;
            return;
        }
        
        myStr = (char *)malloc(lena);
        for(int i=0;i<lena;i++)
        {
            //myStr[i] = a[i];
            *(myStr+i)=a[i];
        }
        m_len = lena;
    }
    ~MyString() { 
        if (m_len >= 16) {
           free(myStr);
        }
    }
    
    int length()
    {
       return m_len;
        //return strlen(myStr); // O(N)
    }
    
    private:
       
    
};

stack: 7ffd7e69a5e0

heap: 1420c60

rw data 400ed7

ro data  401535

code function  400ed7

int main(){
    
    test();
    
    static char global_arr[] = "apple"; // rw region - read modify region
    const char *pstr = "123456789012345"; // ro region - read only region - close to main
    //std::string a =  pstr;   //10 characters = 10bytes
    
    std::string a =  "123456789012345";
    a[9] = '\0';
    
    MyString s(a);
    
    cout << s.myStr << endl;
    
    cout << "sizeof myStr:" << sizeof(MyString) << " len:" << s.length() << endl; //
    
00
    
    cout << "sizeof a:" << sizeof(a) <<  " len:" << a.length() << endl; // 32 bytes.
    
    cout << "string raw ptr:" << hex << ((long long)a.c_str()) << endl;
    // internal variable called buffer16
    
    cout << "string raw myStr:" << hex << ((long long)s.myStr)  << endl;
    
    cout << "string pstr:" << hex << ((long long)pstr)  << endl;
     cout << "global arr:" << hex << ((long long)global_arr)  << endl;
    
    cout << "main address:" << ((long long) main) << endl;
    
    
    
    
    

    char ch;
    cout << sizeof(ch) << endl; // 1 
    
    int i;
    cout << sizeof(i) << endl; // 4
    
    
    char *p = &ch;
    cout << sizeof(p) << endl;  // 8 bytes
    
    
    return 0;
}

*/