#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void print(stack<int>st){
    while(st.size()!=0){
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main(){
stack<int>st;
st.push(10);
st.push(20);
st.push(30);
st.push(40);
st.push(50);
print(st);
cout<<endl;
stack<int>rt;
stack<int>gt;
while(st.size()!=0){
    rt.push(st.top());
    st.pop();
}
while(rt.size()!=0){
    gt.push(rt.top());
    rt.pop();
}
print(gt);
    return 0;
}
