#include<iostream>
#include<stack>
#include<vector>
using namespace std;
// void displayrec(stack<int>st){
//     cout<<st.top()<<" ";
//     int x=st.top();
//     st.pop();
//     displayrec(st);
//     st.push(x);
// }
void displayrec1(stack<int>&st){
    if(st.size()==0) return;
    int x=st.top();
    cout<<x<<" ";
    st.pop();
    displayrec1(st);
    st.push(x);
}
int main(){
stack<int>st;
st.push(10);
st.push(20);
st.push(30);
st.push(40);
st.push(50);
// displayrec(st);
cout<<endl;
displayrec1(st);
    return 0;
}