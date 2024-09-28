
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reorder_queue(queue<int>&q){
    int n=q.size()/2;
    int k=n,l=n;
    stack<int>st;
    while(n--){
        st.push(q.front());
        q.pop();
    }
    while(st.size()!=0){
        q.push(st.top());
        st.pop();
    }
    while(l--){
        st.push(q.front());
        q.pop();
    }

    while(k--){
        int x=st.top();
        st.pop();
        q.push(x);
        q.push(q.front());
        q.pop();
    }
}
 void reverse(queue<int>&q){
     stack<int>st;
    while(q.size()!=0){
        st.push(q.front());
        q.pop();
    }
    while(st.size()!=0){
       q.push(st.top());
        st.pop();
 }
 }
void display(queue<int>q){
    while(q.size()!=0){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    display(q);
    reorder_queue(q);

    reverse(q);

    display(q);
    return 0;
}