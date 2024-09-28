#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void displayrec1(stack<int>&st){
    if(st.size()==0){
      return ;
    } 
    int x=st.top();
    st.pop();
    displayrec1(st);
    cout<<x<<" ";
    st.push(x);
}
void pushatbottom(stack<int>&st,int val){
    if(st.size()==0){
        st.push(val);
      return ;
    } 
    int x=st.top();
    st.pop();
    pushatbottom(st,val);
    st.push(x);
}
void reverse(stack<int>&st){
    if(st.size()==1) return;
    int x=st.top();
    st.pop();
    reverse(st);
    pushatbottom(st,x);
}
int main(){
stack<int>st;
st.push(10);
st.push(20);
st.push(30);
st.push(40);
st.push(50);
displayrec1(st);
cout<<endl;
reverse(st);
displayrec1(st);
    return 0;
}