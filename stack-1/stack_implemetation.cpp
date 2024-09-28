#include<iostream>
using namespace std;
class Stack{
    public:
    int arr[5];
    int idx=-1;

void push(int val){
    if(idx==sizeof(arr)/sizeof(arr[0])){
        cout<<"Stack is full"<<endl;
        return ;
    }
    idx++;
    arr[idx]=val;
}
void pop(){
    if(idx==-1){
        cout<<"Stack is empty"<<endl;
        return;
    }
    idx--;
}
int top(){
    if(idx==-1){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    return arr[idx];
}
int size(){
    return idx+1;
}
void display(){
    for(int i=0;i<idx;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
};
int main(){
    Stack st;
    st.push(45);
    st.push(67);
    st.push(89);
    st.push(90);
    st.push(80);
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    st.display();
    return 0;
}
