#include<iostream>
#include<vector>
using namespace std;
class Stack{
    public:
   vector<int>v;
    int idx=-1;

void push(int val){
    v.push_back(val);
}
void pop(){
    if(v.size()==0){
        cout<<"Stack is empty"<<endl;
        return;
    }
    v.pop_back();
}
int top(){
     if(v.size()==0){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    return v[v.size()-1];
}
int size(){
    return v.size();
}
};
int main(){
    Stack st;
    st.push(45);
    st.push(67);
    st.push(89);
    st.push(90);
    st.push(80);
    st.push(60);
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    return 0;
}
