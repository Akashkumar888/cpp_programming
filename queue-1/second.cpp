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
// empty use only then chech true or false 
while(q.size()!=0){
    cout<<q.front()<<" ";
    q.pop();
}


    return 0;
}