
class MyQueue {
public:
stack<int>st;
stack<int>helper;
    MyQueue() {
                // constuctor hai 
    }
    
    void push(int x) { 
        if(st.size()==0){
        st.push(x);
        return ;
        } 
        while(st.size()!=0){
            helper.push(st.top());
            st.pop();
        }
        st.push(x);
        while(helper.size()!=0){
            st.push(helper.top());
            helper.pop();
        }
    }
    int pop() {
        int x=st.top();
        st.pop();
      return  x;
    }
    
    int peek() { // front 
      int x=st.top();  
      return x;
    }
    
    bool empty() {
        return st.size()==0;
    }
};

class myQueue {
  public:
  stack<int>st;
stack<int>helper;
    myQueue() {
        // Initialize your data members
    }

    void enqueue(int x) {
        // Implement enqueue operation
        if(st.size()==0){
        st.push(x);
        return ;
        } 
        while(st.size()!=0){
            helper.push(st.top());
            st.pop();
        }
        st.push(x);
        while(helper.size()!=0){
            st.push(helper.top());
            helper.pop();
        }
    }

    void dequeue() {
        // Implement dequeue operation
        if(st.empty())return ;
        int x=st.top();
        st.pop();
    }

    int front() {
        // Implement front operation
        if(st.empty())return -1;
        int x=st.top();  
        return x;
    }

    int size() {
        // Implement size operation
        return st.size();
    }
};
