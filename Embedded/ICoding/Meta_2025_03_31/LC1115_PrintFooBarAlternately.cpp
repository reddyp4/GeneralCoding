/*
1115. Print FooBar Alternately
Solved
Medium
Topics
Companies
Suppose you are given the following code:

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
The same instance of FooBar will be passed to two different threads:

thread A will call foo(), while
thread B will call bar().
Modify the given program to output "foobar" n times.

 

Example 1:

Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
"foobar" is being output 1 time.
Example 2:

Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.
 

Constraints:

1 <= n <= 1000
*/

class FooBar {
    private:
        int n;
        int val=0;
        pthread_mutex_t m;
        pthread_cond_t cv;
    
    public:
        FooBar(int n) {
            this->n = n;
    
            pthread_mutex_init(&(this->m),NULL);
            pthread_cond_init(&(this->cv),NULL);
            this->val=0;
        }
    
        void foo(function<void()> printFoo) {
            
            for (int i = 0; i < n; i++) {
                pthread_mutex_lock(&(this->m));
                while(this->val==1) pthread_cond_wait(&(this->cv),&(this->m));
                //if you are here, cond var is signaled, val=0
    
                // printFoo() outputs "foo". Do not change or remove this line.
                printFoo();
    
                this->val=1;
                pthread_mutex_unlock(&this->m);
                pthread_cond_broadcast(&(this->cv));
            }
        }
    
        void bar(function<void()> printBar) {
            
            for (int i = 0; i < n; i++) {
                pthread_mutex_lock(&(this->m));
                while(this->val==0) pthread_cond_wait(&(this->cv),&(this->m));
                //if you are here, val=1, cv has been signaled
    
                // printBar() outputs "bar". Do not change or remove this line.
                printBar();
    
                this->val=0;
                pthread_mutex_unlock(&(this->m));
                pthread_cond_broadcast(&(this->cv));
            }
        }
    };