#include<iostream>
#include<stack>
using namespace std;
void print(stack<int>st){
while(st.size()!=0){
    cout<<st.top()<<" ";
    st.pop();
}
}
int main(){
stack<int>st;
stack<int>temp;
stack<int>gt;
st.push(10);
st.push(20);
st.push(30);
st.push(40);
st.push(50);

print(st);
cout<<endl;
while(st.size()!=0){
    temp.push(st.top());
    st.pop();
    
}
while(temp.size()!=0){
    gt.push(temp.top());
    temp.pop();
}
while(gt.size()!=0){
    st.push(gt.top());
    gt.pop();
}
print(st);
    return 0;
}