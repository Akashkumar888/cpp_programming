#include<iostream>
#include<stack>
using namespace std;
int main(){
stack<int>s;
s.push(56);
s.push(46);
s.push(78);
s.push(45);
s.push(767);
cout<<"Top element :"<<s.top()<<endl;
s.pop();
cout<<"Top element :"<<s.top()<<endl;
cout<<"Size of stack :"<<s.size()<<endl;
cout<<"Empty or not :"<<s.empty()<<endl;
while(!s.empty()){
    cout<<s.top()<<endl;
    s.pop();
}

    return 0;
}