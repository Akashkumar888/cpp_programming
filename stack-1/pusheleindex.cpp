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
void pushatIndex(stack<int>&st,int idx,int val){
stack<int>rt;
for(int i=0;i<=idx;i++){
    rt.push(st.top());
    st.pop();
}
st.push(val);
while(rt.size()!=0){
    st.push(rt.top());
    rt.pop();
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
pushatIndex(st,2,79);
print(st);
    return 0;
}