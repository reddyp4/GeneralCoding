// Compiled with: g++ -Wall -std=c++14 -pthread

#include <iostream>
#include <vector>
#include <pair>

using namespace std;

/*

Google Interview

   Snake Game
   
   
   [S].   [F]
      
   
   Dir:  forward, left, right



       [S][H]


          [S][H]
        
             [8]
             [7]
             [6][5][4]
                   [3]
                   [2][H]
                   
                   
             
             [8]
             [7][6][5]
                   [4]
                   [3][2][H]
                       --->
                   
*/

struct Board {
    // S = snake
    // F = food
    Board(vector<pair<int,int>> snake, vecotr<pair<int,int>> foods) {
    }
    
    char array[16][16];  
};

// Circular Buffer Size fixed 
struct Snake {
    
    vector<pair<int,int>> this_snake[16];    // [0][0], [0],[1].  ->. [S][H], [0][0],[1][0]  [S]
    //                                                                               [H]
    int power[16];
    
    int head_idx;
    int tail_idx;
    std::mutex mut;
    std::condition_variable not_large;
    
    // producer: ISR (muliple writer)
    // consumer:  process_event thread (single)
    
    std::deque<array<int,2>> events[16];    //events queue from interrupt, fixed size
    vector<int,int> board;
   
    // producer: process_event thread
    // consumer: display thread
    std::deque<vector<int>> display_queue; // can grow dynamically
    
    public:
    Snake(const vector<pair<int,int>> & snake) : this_snake(snake) {   
        
        head_idx = 0;
        tail_idx = snake.size()-1;
    }
    
    
    enum Opcode {
        FORWARD=0,
        LEFT,
        RIGHT,
        COUNT
    };
 
    //consumer to screen, say 1s
    void display_board()
    {
         // 2*S cells.
        auto changes = display_queue.front(); display_queue.pop();
        apply_change(board, changes);
        // display func - over display driver
        display(board);
       
        
        //print
    }

    //thread
    void isr_event(int dx, int dy, int snakeId) {
   
       // push event to event queue
     
        event[snakeId].push_to_back({dx, dy});
     
    }
    
    //from UART handler-multiple producer
    void process_event_cb() {
        
        
        // indirect sory
        
        vector<int> shorted_array(16);
        for(int i = 0; i < 16; ++i) {
            shorted_array[i] = i;
        }
        // 0 1. 2 ... 15
        
        // sort snake by power in from max_power to min_power
        sort(shorted_array.begin(), shorted_array.end(), [&](int i, int j) {
            return power[i] > power[j];
        });
        
        // 3, 1 0 15 14..... 
        
        for(int idx : shorted_array) {
                    //check all snake id's and push only to one(larger)
            auto & q = events[idx];
            {
                if (can_move(e)) {
                   pop_from_tail(idx);
                   push_to_front(idx, dx, dy);
                }   
            }
        }

    }
    
    void pop_from_tail(int snakeID)
    {
        auto tail = this_name[tail_idx];
        //board[tail.first][tail.second] = ' ';
        display_queue.push({snakeID, tail, ' '}; 
        tail_idx=(tail_idx+1)%this_snake.size();
        
    }
    
    void push_to_front(int snakeID, int dx, int dy)
    {
        auto h = this_snake[head_idx];
        h.first += dx;
        h.second += dy;
        head_id = (head_idx+1)%this_snake.size();
        
        //this_snake[head_id] = {h.first+dx, h.second+dy};
        display_queue.push({snakeID, head}};
        board[head.first][head.second] = snakeID;
        
    }
};

int main(){
    cout << "Hello, World!" << endl;
    return 0;
}
