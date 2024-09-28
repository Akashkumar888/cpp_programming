
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void display(queue<int>q){
    while(q.size()!=0){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main(){
    int k;
    cout<<"Enter k: ";
    cin>>k;
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    display(q);
    int q_size=q.size()-k;
    stack<int>st;
    while(k--){
        st.push(q.front());
        q.pop();
    }
    while(st.size()!=0){
        q.push(st.top());
        st.pop();
    }
    while(q_size--){
        int x=q.front();
        q.pop();
        q.push(x);
    }
    display(q);

    return 0;
}
