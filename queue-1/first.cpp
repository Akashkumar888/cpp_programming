#include<iostream>
#include<queue>
using namespace std;
int main(){
queue<int>q;


q.push(10);
q.push(20);
q.push(30);
q.push(40);
q.push(50);
cout<<q.front()<<endl; 
cout<<q.back()<<endl; // rear nhi back keyword hota hai
cout<<q.size()<<endl;
cout<<q.empty()<<endl;
q.pop();
cout<<q.front()<<endl;
    return 0;
}