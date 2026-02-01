
class MyStack {
public:
queue<int>q1;
queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(q1.size()!=0){
            q2.push(q1.front());
            q1.pop();
        }
        while(q2.size()!=0){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int x=q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        int x=q1.front();
        return x;
    }
    
    bool empty() {
        return q1.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


 class MyStack {
public:
queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x=q.front();
        q.pop();
        return x;
    }
    
    int top() {
        int x=q.front();
        return x;
    }
    
    bool empty() {
        return q.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

 class myStack {
    queue<int> q;
  public:
    void push(int x) {
        // Inserts an element x at the top of the stack
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        // Removes an element from the top of the stack
        if(q.empty())return ;
        int x=q.front();
        q.pop();
    }

    int top() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(q.empty())return -1;
        int x=q.front();
        return x;
    }

    int size() {
        // Returns the current size of the stack
        return q.size();
    }
};
