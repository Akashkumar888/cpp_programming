
class MinStack {
public:
stack<int>st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int>helper;
        int mn=INT_MAX;
        while(!st.empty()){
            mn=min(mn,st.top());
            helper.push(st.top());
            st.pop();
        }
        while(!helper.empty()){
            st.push(helper.top());
            helper.pop();
        }
        return mn;
    }
};



class MinStack {
public:
stack<int>st;
stack<int>helper;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(helper.size()==0 || val<helper.top()){
         helper.push(val);
        }
        else if(val>=helper.top()){
        helper.push(helper.top());
        }
    }
    
    void pop() {
        st.pop();
        helper.pop();
    }
    
    int top() {
        return st.top();
    }
    int getMin() {
        return helper.top();
    }
};


class MinStack {
public:
vector<int>v;
stack<int>helper;
    MinStack() {
        
    }
    
    void push(int val) {
        v.push_back(val);
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v[v.size()-1];
    }
    int getMin() {
       int mn=v[0];
       for(int i=1;i<v.size();i++){
        mn=min(mn,v[i]);
       }
       return mn;
    }
};


class MinStack {
public:
stack<long long>st;
long long mn;
    MinStack() {// constructure 
        mn=LLONG_MAX;
    }
    
    void push(int val) {
        long long x=(long long)val;
       if(st.size()==0 ){
        st.push(x);
        mn=x;
       }else if(x>=mn){
        st.push(x);
       }else{
        st.push(2*x-mn);
        mn=x;
       }
    }
    
    void pop() {
        if(st.top()<mn){
            int oldmin=2*mn-st.top();
            mn=oldmin;
        }
        st.pop();
    }
    
    int top() {
       if(st.top()<mn) return mn;
       return st.top();
    }
    int getMin() {
     return mn;
    }
};


class MinStack {
public:
stack<long long>st;
  long long mini;
    MinStack() {
        mini=LLONG_MAX;
    }
    
    void push(int val) {
        long long newval=(long long)val;
        if(st.empty()){
            mini=newval;
            st.push(newval);
        }
        else{
            if(newval>mini)st.push(newval);
            else {
            st.push(2*newval-mini);
            mini=newval;
            }
        }
    }
    
    void pop() {
        if(st.empty())return;
        long long ele=st.top();
        st.pop();
        if(ele<mini){
            mini=2*mini-ele;
        }
    }
    
    int top() {
        if(st.empty())return -1;
        long long topval=st.top();
        if(mini<topval)return topval;
        return mini;
    }
    
    int getMin() {
        if(st.empty())return -1;
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


 class MinStack {
public:
stack<long long>st;
  long long mini;
    MinStack() {
        mini=LLONG_MAX;
    }
    
    void push(int val) {
        long long newval=(long long)val;
        if(st.empty()){
            mini=newval;
            st.push(newval);
        }
        else{
            if(newval>mini)st.push(newval);
            else {
            st.push(2*newval-mini);
            mini=newval;
            }
        }
    }
    
    void pop() {
        if(st.empty())return;
        long long ele=st.top();
        st.pop();
        if(ele<mini){
            mini=2*mini-ele;
        }
    }
    
    int top() {
        if(st.empty())return -1;
        long long topval=st.top();
        if(mini<topval)return topval;
        return mini;
    }
    
    int getMin() {
        if(st.empty())return -1;
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 