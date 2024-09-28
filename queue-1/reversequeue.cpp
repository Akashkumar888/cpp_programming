

#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void print(queue<int>&q){
    int n=q.size();
    for(int i=1;i<=n;i++){
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
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
int main(){
queue<int>q;
q.push(10);
q.push(20);
q.push(30);
q.push(40);
q.push(50);
q.push(60);
print(q);
reverse(q);
print(q);
    return 0;
}
